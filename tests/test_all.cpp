
#include "core/types.hpp"
#include "packet/packet.hpp"
#include "ioc/ioc.hpp"
#include "rules/rules.hpp"
#include "policy/policy.hpp"
#include <cassert>
using namespace threatlens; int main(){auto ip=core::parse_ipv4("192.168.1.5");assert(ip&&ip->is_private());auto c=core::parse_cidr("192.168.1.0/24");assert(c&&c->contains(*ip));auto i=ioc::parse_ioc_text("192.168.1.5,high,90\nexample.com\n10.0.0.0/8\n");assert(i.value.indicators.size()==3);auto rs=rules::parse_rules("alert tcp any any -> 192.168.1.5 443 (msg:\"test\"; content:\"Host\"; sid:1; rev:1;)\n");assert(rs.value.rules.size()==1);assert(rules::validate_rule(rs.value.rules[0]).empty());auto po=policy::parse_policy("iptables -A INPUT -p tcp -s 10.0.0.0/8 --dport 22 -j ACCEPT\niptables -A INPUT -p tcp --dport 22 -j DROP\n");assert(po.value.rules.size()==2);return 0;}
