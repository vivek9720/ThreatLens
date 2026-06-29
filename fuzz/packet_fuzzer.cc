#include "packet/packet.hpp"
extern "C" int LLVMFuzzerTestOneInput(const uint8_t*d,size_t s){auto r=threatlens::packet::parse_pcap({d,s});for(auto&m:threatlens::packet::extract_metadata(r.value))(void)m.summary;if(s>14){auto e=threatlens::packet::parse_ethernet({d,s});if(e.value.payload.size)(void)threatlens::packet::parse_ipv4_packet(e.value.payload);}return 0;}
