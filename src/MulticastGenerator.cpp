#include "MulticastGenerator.h"
#include <iostream>
#include <stdexcept>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

MulticastGenerator::MulticastGenerator() : sock(socket(AF_INET, SOCK_DGRAM, 0)), messages({"Hello", " from", " Multicast!\n"}) {
    if (sock == -1) {
        throw std::runtime_error("Cannot create socket");
    }
    multicastAddress.sin_family = AF_INET;
    multicastAddress.sin_addr.s_addr = inet_addr("232.0.0.1");
    multicastAddress.sin_port = htons(16000);
};

MulticastGenerator::~MulticastGenerator() {
    close(sock);
};

void MulticastGenerator::Generate() {
    for (const std::string& message : messages) {
        sendto(sock, message.c_str(), message.size(), 0, (struct sockaddr*) &multicastAddress, sizeof(multicastAddress));
    }
};