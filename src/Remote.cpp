#include <boost/asio.hpp>
#include "Remote.hpp"

using boost::asio::ip::tcp;
using boost::asio::ip;
using namespace Sinc;

address const Remote::getIpAddress() {
    return ipaddress;
}
