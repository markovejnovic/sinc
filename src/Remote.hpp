#pragma once

#include <boost/asio.hpp>

using boost::asio::ip::tcp;
using boost::asio::ip;

namespace Sinc
{
    class Remote {
    private:
        const address ipAddress;

    public:
        address const getIpAddress();

        Remote(address other) : ipAddres(other) {}
    }
}
