#pragma once


#include <simple-websocket-server/server_ws.hpp>

using WsServer = SimpleWeb::SocketServer<SimpleWeb::WS>;

class WebSocket {
  void RunServer();
  void SendFrame();
};