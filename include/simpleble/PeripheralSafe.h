#pragma once

#include <optional>

#include <simpleble/Peripheral.h>

namespace SimpleBLE {

class PeripheralSafe : public Peripheral {
  public:
    PeripheralSafe(Peripheral& peripheral);
    ~PeripheralSafe();

    std::optional<std::string> identifier() noexcept;
    std::optional<BluetoothAddress> address() noexcept;

    bool connect() noexcept;
    bool disconnect() noexcept;
    std::optional<bool> is_connected() noexcept;
    std::optional<bool> is_connectable() noexcept;

    std::optional<std::vector<BluetoothService>> services() noexcept;
    std::optional<std::map<uint16_t, ByteArray>> manufacturer_data() noexcept;

    std::optional<ByteArray> read(BluetoothUUID service, BluetoothUUID characteristic) noexcept;
    bool write_request(BluetoothUUID service, BluetoothUUID characteristic, ByteArray data) noexcept;
    bool write_command(BluetoothUUID service, BluetoothUUID characteristic, ByteArray data) noexcept;
    bool notify(BluetoothUUID service, BluetoothUUID characteristic,
                std::function<void(ByteArray payload)> callback) noexcept;
    bool indicate(BluetoothUUID service, BluetoothUUID characteristic,
                  std::function<void(ByteArray payload)> callback) noexcept;
    bool unsubscribe(BluetoothUUID service, BluetoothUUID characteristic) noexcept;

    bool set_callback_on_connected(std::function<void()> on_connected) noexcept;
    bool set_callback_on_disconnected(std::function<void()> on_disconnected) noexcept;
};

}  // namespace SimpleBLE
