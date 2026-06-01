//
// Created by kris on 26/5/2026.
//

#ifndef PROYECTO_2___KRIS_Y_DEREK_CHANNELSCONTROLLER_H
#define PROYECTO_2___KRIS_Y_DEREK_CHANNELSCONTROLLER_H

#include "../Observer/Channel.h"
#include "../Iterator/ConcreteIterator.h"
#include "../Exceptions/NoExistingChannels.h"
#include "../Exceptions/MissingChannel.h"

class ChannelsController {
private:
    std::shared_ptr<ListInterface<Channel>> channelsList;
public:
    ChannelsController();
    std::string addChannel(std::shared_ptr<Channel>);
    std::shared_ptr<Channel> searchChannel(std::string);
    bool existingChannel(std::string);
    std::shared_ptr<ListInterface<Channel>> getChannelsList();
    std::string showChannelsList();
};


#endif //PROYECTO_2___KRIS_Y_DEREK_CHANNELSCONTROLLER_H