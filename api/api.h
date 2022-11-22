#ifndef GO_PROBE_EBPF_API_H
#define GO_PROBE_EBPF_API_H

#include <initializer_list>

struct API {
    const char *name;
    const char *probe;
    bool ignoreCase;
};

constexpr auto GOLANG_API = {
        API {
                "os/exec.Command",
                "os_exec_command",
                false
        },
        {
                "os/exec.(*Cmd).Start",
                "os_exec_cmd_start",
                false
        },
        {
                "os.OpenFile",
                "os_openfile",
                false
        },
        {
                "os.Remove",
                "os_remove",
                false
        },
        {
                "os.RemoveAll",
                "os_remove_all",
                false
        },
        {
                "os.Rename",
                "os_rename",
                true
        },
        {
                "io/ioutil.ReadDir",
                "io_ioutil_readdir",
                false
        },
        {
                "net.Dial",
                "net_dial",
                false
        },
        {
                "net.DialTCP",
                "net_dial_tcp",
                false
        },
        {
                "net.DialIP",
                "net_dial_ip",
                false
        },
        {
                "net.DialUDP",
                "net_dial_udp",
                false
        },
        {
                "net.DialUnix",
                "net_dial_unix",
                false
        },
        {
                "net.(*Dialer).DialContext",
                "net_dialer_dial_context",
                false
        },
        {
                "net.ResolveTCPAddr",
                "net_resolve_tcp_address",
                false
        },
        {
                "net.ResolveIPAddr",
                "net_resolve_ip_address",
                false
        },
        {
                "net.ResolveUDPAddr",
                "net_resolve_udp_address",
                false
        },
        {
                "net.ResolveUnixAddr",
                "net_resolve_unix_address",
                false
        },
        {
                "net.LookupAddr",
                "net_lookup_address",
                false
        },
        {
                "net.LookupCNAME",
                "net_lookup_cname",
                false
        },
        {
                "net.LookupHost",
                "net_lookup_host",
                false
        },
        {
                "net.LookupPort",
                "net_lookup_port",
                false
        },
        {
                "net.LookupTXT",
                "net_lookup_txt",
                false
        },
        {
                "net.LookupIP",
                "net_lookup_ip",
                false
        },
        {
                "net.LookupMX",
                "net_lookup_mx",
                false
        },
        {
                "net.LookupNS",
                "net_lookup_ns",
                false
        },
        {
                "net.(*Resolver).LookupAddr",
                "net_resolver_lookup_address",
                true
        },
        {
                "net.(*Resolver).LookupCNAME",
                "net_resolver_lookup_cname",
                true
        },
        {
                "net.(*Resolver).LookupHost",
                "net_resolver_lookup_host",
                false
        },
        {
                "net.(*Resolver).LookupPort",
                "net_resolver_lookup_port",
                false
        },
        {
                "net.(*Resolver).LookupTXT",
                "net_resolver_lookup_txt",
                true
        },
        {
                "net.(*Resolver).LookupIPAddr",
                "net_resolver_lookup_ip_address",
                false
        },
        {
                "net.(*Resolver).LookupMX",
                "net_resolver_lookup_mx",
                true
        },
        {
                "net.(*Resolver).LookupNS",
                "net_resolver_lookup_ns",
                true
        },
        {
                "net.Listen",
                "net_listen",
                false
        },
        {
                "net.ListenTCP",
                "net_listen_tcp",
                false
        },
        {
                "net.ListenIP",
                "net_listen_ip",
                false
        },
        {
                "net.ListenUDP",
                "net_listen_udp",
                false
        },
        {
                "net.ListenUnix",
                "net_listen_unix",
                false
        },
        {
                "net/http.NewRequest",
                "net_http_new_request",
                false
        },
        {
                "net/http.NewRequestWithContext",
                "net_http_new_request_with_context",
                false
        },
#ifdef ENABLE_HTTP
        {
                "net/http.serverHandler.ServeHTTP",
                "on_request",
                false
        },
        {
                "net/http.(*response).finishRequest",
                "on_request_finished",
                false
        },
        {
                "net/http.(*response).Hijack",
                "on_request_finished",
                false
        },
#endif
        {
                "plugin.Open",
                "plugin_open",
                false
        }
};

#endif //GO_PROBE_EBPF_API_H
