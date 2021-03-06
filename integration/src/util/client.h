#pragma once

#include <p2psc.h>
#include <src/util/stateful_socket.h>

namespace p2psc {
namespace integration {
namespace util {

class Client {
public:
  Client(const p2psc::Peer &peer, const p2psc::Mediator &mediator,
         const p2psc::key::Keypair &keypair)
      : _peer(peer), _mediator(mediator), _keypair(keypair) {}

  std::shared_ptr<StatefulSocket> connect_async();
  std::shared_ptr<StatefulSocket> connect_sync(uint64_t timeout_ms);

private:
  p2psc::Peer _peer;
  p2psc::Mediator _mediator;
  p2psc::key::Keypair _keypair;
};
}
}
}