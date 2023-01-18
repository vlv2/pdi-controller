#include <string_view>

#include <fmt/format.h>

#include <amqp.h>
#include <amqp_tcp_socket.h>

int main() {
    static constexpr std::string_view LISTENER_QUEUE {"RabbitMQ.Listener"};
    static constexpr std::string_view PUBLISH_QUEUE {"gRPC.Listener"};
    static constexpr amqp_channel_t CHANNEL = 1;

    amqp_connection_state_t conn = amqp_new_connection();
    amqp_socket_t *socket = amqp_tcp_socket_new(conn);

    amqp_socket_open(socket, "localhost", AMQP_PROTOCOL_PORT);
    amqp_login(conn,
               "/",
               AMQP_DEFAULT_MAX_CHANNELS,
               AMQP_DEFAULT_FRAME_SIZE,
               0,
               AMQP_SASL_METHOD_PLAIN,
               "guest",
               "guest");

    amqp_channel_open(conn, CHANNEL);
    amqp_queue_declare(conn,
                       CHANNEL,
                       amqp_cstring_bytes(LISTENER_QUEUE.c_str()),
                       false,
                       false,
                       false,
                       false,
                       amqp_empty_table);
    amqp_basic_consume(conn,
                       CHANNEL,
                       amqp_cstring_bytes(LISTENER_QUEUE.c_str()),
                       amqp_empty_bytes,
                       false,
                       true,
                       false,
                       amqp_empty_table);

    while (true) {
        amqp_maybe_release_buffers(conn);
        amqp_envelope_t envelope;
        amqp_consume_message(conn, &envelope, nullptr, 0);

        std::string_view sw {static_cast<char *>(envelope.message.body.bytes),
                             envelope.message.body.len};

        fmt::print("[x] Received {} | Size: {}\n", sw, sw.length());
        amqp_destroy_envelope(&envelope);

        amqp_basic_publish(conn,
                           CHANNEL,
                           amqp_empty_bytes,
                           amqp_cstring_bytes(PUBLISH_QUEUE.c_str()),
                           false,
                           false,
                           nullptr,
                           amqp_cstring_bytes(" and hello fom RabbitMQ!"));

        if (sw == "close") {
            break;
        }
    }

    amqp_channel_close(conn, CHANNEL, AMQP_REPLY_SUCCESS);
    amqp_connection_close(conn, AMQP_REPLY_SUCCESS);
    amqp_destroy_connection(conn);

    return 1;
}
