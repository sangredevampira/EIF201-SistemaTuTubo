//
// Created by XPC on 30/5/2026.
//

#include "DuplicatedChannel.h"

DuplicatedChannel::DuplicatedChannel()
    : GeneralException("El canal que se intenta registrar ya existe en la plataforma. Intenta con otro nombre o inicia sesion con tu cuenta")
{}
