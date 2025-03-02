﻿using System.IO;

namespace ImaginationServer.Common.Packets
{
    public abstract class OutgoingPacket
    {
        public abstract void Serialize(WBitStream bitStream);

        public void WriteHeader(WBitStream bitStream, ushort remoteConnection, uint packetId)
        {
            bitStream.Write((byte)83);
            bitStream.Write(remoteConnection);
            bitStream.Write(packetId);
            bitStream.Write((byte)0);
        }
    }

    public abstract class IncomingPacket
    {
        protected IncomingPacket(BinaryReader binaryReader)
        {
        }
    }
}