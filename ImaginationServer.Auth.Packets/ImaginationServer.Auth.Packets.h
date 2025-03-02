// ImaginationServer.Auth.Packets.h

#pragma once

#include "Stdafx.h"
#include <BitStream.h>

using namespace System;
using namespace ImaginationServer::Common;
using namespace RakNet;

namespace ImaginationServerAuthPackets {

	public ref class AuthPackets
	{
		static void CreateExtraPacketData(unsigned long stampId, signed long bracketNum, unsigned long afterNum, RakNet::BitStream *bitStream) {
			unsigned long zeroPacket = 0;

			bitStream->Write(stampId);
			bitStream->Write(bracketNum);
			bitStream->Write(afterNum);
			bitStream->Write(zeroPacket);
		}
	public:
		static void SendLoginResponse(String^ address, unsigned char success, String^ userkey, LuServer^ peer);

		static void WriteStringToBitStream(const char* myString, int stringSize, int maxChars, RakNet::BitStream* output)
		{
			// Write the string to provided BitStream along with the size
			output->Write(myString, stringSize);

			// Check to see if there are any bytes remaining according to user
			// specification
			auto remaining = maxChars - stringSize;

			// If so, fill with 0x00
			for (auto i = 0; i < remaining; i++)
			{
				unsigned char zero = 0;

				output->Write(zero);
			}
		}

		static void CreatePacketHeader(MessageID messageId, unsigned short connectionType, unsigned long internalPacketId, BitStream* output)
		{
			unsigned char unknown1 = 0; // This is an unknown uchar

										// Write data to provided BitStream
			output->Write(messageId);
			output->Write(connectionType);
			output->Write(internalPacketId);
			output->Write(unknown1);
		}
	};
}
