#pragma once

#include "Arduino.h"
#include "Packet.hpp"
#include "../ParsingInformation.hpp"
#include "../Callbacks.hpp"

namespace AsyncMqttClientInternals {
class ConnAckPacket : public Packet {
  constexpr static size_t POS_FLAGS = 0;
  constexpr static size_t POS_REASON = 1;
  constexpr static size_t POS_PROPERTIES = 2;

 public:
  explicit ConnAckPacket(ParsingInformation* parsingInformation, OnConnAckInternalCallback callback);
  ~ConnAckPacket() override;

  void parseData(uint8_t* data, size_t len, size_t& currentBytePosition) override;

 private:
  ParsingInformation* _parsingInformation;
  OnConnAckInternalCallback _callback;

  uint8_t _bytePosition;
  bool _sessionPresent;
  AsyncMqttClientInternals::ConnectReason _reason;

  uint32_t propertiesLength;
  bool propertyLengthRead;
  std::vector<uint8_t> properties;

};
}  // namespace AsyncMqttClientInternals
