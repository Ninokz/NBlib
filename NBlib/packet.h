#pragma once
#include <iostream>
#include <memory>

#include <boost/asio.hpp>

namespace Nano
{
	namespace Communication
	{
		class Packet
		{
		public:
			typedef std::shared_ptr<Packet> Ptr;
			typedef unsigned short SizeType;

			static const int PACKET_HEAD_SIZE = 4;
			static const int PACKET_MAX_SIZE = 1024;
		public:
			Packet();
			Packet(unsigned short size);
			virtual ~Packet();

			Packet(const Packet& other);
			Packet& operator=(const Packet& other);

			std::string toString() const;
		public:
			char* m_data;
			unsigned short m_size;
		};

		class RecvPacket : public Packet
		{
		public:
			typedef std::shared_ptr<RecvPacket> Ptr;
		public:
			RecvPacket() = delete;
			RecvPacket(unsigned short size);
			void clear();
		};

		class SendPacket : public Packet
		{
		public:
			typedef std::shared_ptr<SendPacket> Ptr;
		public:
			SendPacket() = delete;
			SendPacket(unsigned short size) = delete;
			SendPacket(const char* data, unsigned short size);
		};
	}
}