//
// Created by kris on 26/5/2026.
//

#include "ChannelsController.h"

ChannelsController::ChannelsController() { channelsList = std::make_shared<List<Channel>>(); }

std::shared_ptr<ListInterface<Channel>> ChannelsController::getChannelsList() {
    return channelsList;
}

std::string ChannelsController::addChannel(std::shared_ptr<Channel> newChannel) {
    channelsList->insertFirst(newChannel);
    return "* Canal registrado exitosamente!";
}

std::shared_ptr<Channel> ChannelsController::searchChannel(std::string channelName) {
    if (channelsList->isEmpty()) throw NoExistingChannels();

    std::shared_ptr<Channel> channel = nullptr;
    auto iterator = channelsList->createIterator();
    bool found = false;

    while (iterator->hasNext())
    {
        auto currentChannel = iterator->getNext();

        if (currentChannel->getName() == channelName)
        {
            found = true;
            channel = currentChannel;
            break;
        }
    }

    if (!found) throw MissingChannel();

    return channel;
}

bool ChannelsController::existingChannel(std::string channelName)
{
    bool found = false;

    auto iterator = channelsList->createIterator();

    while (iterator->hasNext())
    {
        auto currentChannel = iterator->getNext();

        if (currentChannel->getName() == channelName) found = true;
    }


    return found;
}

std::string ChannelsController::showChannelsList() {
    if (channelsList->isEmpty()) {
        throw NoExistingChannels();
    }

    return channelsList->showList();
}
