//
// Created by kpilavov on 28.03.23.
//

#include <boost/asio.hpp>
#include <fstream>
#include <iostream>


#define PORT 55555
#define BUFFER_SIZE 256


using boost::asio::ip::tcp;


int main() {
    boost::asio::io_context io_context;

    // Create a TCP server
    tcp::acceptor acceptor(io_context, tcp::endpoint(boost::asio::ip::address::from_string("127.0.0.1"), PORT));

    // Wait for a client to connect
    tcp::socket socket(io_context);
    acceptor.accept(socket);
    std::cout << "client connected" << std::endl;


    // Open the file to be sent
    std::ifstream file("response.txt", std::ios::binary);

    // Read the file by 256 chars and send them
    char buffer[BUFFER_SIZE];
    while (file.read(buffer, sizeof(buffer)).gcount() > 0) {
        boost::asio::write(socket, boost::asio::buffer(buffer, file.gcount()));
    }
    std::cout << "file sent" << std::endl;

    // Close the file and the socket
    file.close();
    socket.close();

    return 0;
}
