#ifndef MULTICASTGENERATOR_H
#define MULTICASTGENERATOR_H

#include <string>
#include <vector>
#include <netinet/in.h>

class MulticastGenerator {
    public:
        MulticastGenerator();
        ~MulticastGenerator();
        void Generate();
    private:
        int sock;
        struct sockaddr_in multicastAddress;
        std::vector<std::string> messages;
};

#endif //MULTICASTGENERATOR_H