cmake_minimum_required(VERSION 4.1)
project(Proyecto_2___Kris_y_Derek)

set(CMAKE_CXX_STANDARD 14)

add_executable(Proyecto_2___Kris_y_Derek
        .idea/workspace.xml
        main.cpp
        Adapter/Video.h
        Utilities/Utilities.h
        Adapter/MP4.cpp
        Adapter/MP4.h
        Adapter/Video.cpp
        Adapter/MPG.cpp
        Adapter/MPG.h
        Adapter/AdapterMPG.cpp
        Adapter/AdapterMPG.h
        README.md
        Iterator/ConcreteIterator.h
        Iterator/List.h
        Iterator/Nodo.h
        Observer/ObserverInterface.h
        Observer/Channel.h
        Observer/Channel.cpp
        Exceptions/GeneralException.h
        Exceptions/GeneralException.cpp
        Exceptions/IncorrectPassword.cpp
        Exceptions/MissingAccount.cpp
        Exceptions/MissingVideo.cpp
        Exceptions/MissingVideo.h
        Exceptions/VideosNotAvailable.cpp
        Exceptions/VideosNotAvailable.h
        Exceptions/NoSuscribers.cpp
        Exceptions/NoSuscribers.h
        Entities/User.cpp
        Entities/User.h
        Entities/UsersController.cpp
        Entities/UsersController.h
        Entities/Authenticator.cpp
        Entities/Authenticator.h
        Exceptions/NoRegisteredUsers.cpp
        Exceptions/NoRegisteredUsers.h
        VideosController.cpp
        VideosController.h
        TuTubo.cpp
        TuTubo.h
)
