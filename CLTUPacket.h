/*
 * CLTUpacket.h
 *
 *  Created on: 12 Dec 2019
 *      Author: Casper Broekhuizen
 */

#ifndef CLTUPACKET_H_
#define CLTUPACKET_H_

#include "Dserial.h"

#define CLTU_MAX_SIZE   64
#define TX_FRAME_BUFFER 8
#define RX_FRAME_BUFFER 8

class CLTUPacket
{
protected:


public:
    uint8_t data[CLTU_MAX_SIZE] = {0};
    int packetSize = CLTU_MAX_SIZE;

    bool isReady = false;
    bool isLocked = false;
    bool isCoded = false;

    int getSize();
    uint8_t* getBytes();
};




#endif /* CLTUPACKET_H_ */
