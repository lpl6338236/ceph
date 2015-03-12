[global]
        fsid = 9f82eb35-1bf6-4c27-8a28-efd62c681aa5
        osd pg bits = 3
        osd pgp bits = 5  ; (invalid, but ceph should cope!)
        osd crush chooseleaf type = 0
        osd pool default min size = 1
        osd failsafe full ratio = .99
        mon osd full ratio = .99
        mon data avail warn = 10
        mon data avail crit = 1
        osd pool default erasure code directory = .libs
        osd pool default erasure code profile = plugin=jerasure technique=reed_sol_van k=2 m=1 ruleset-failure-domain=osd
        rgw frontends = fastcgi, civetweb port=8000
        filestore fd cache size = 32
        run dir = /root/script-ceph/out
        auth supported = cephx
	public network = 10.1.0.0/24
	cluster network = 10.6.0.0/24

[client]
        keyring = /root/script-ceph/ceph.client.admin.keyring
        log file = /root/script-ceph/out/$name.$pid.log
        admin socket = /root/script-ceph/out/$name.$pid.asok

[mds]

        log file = /root/script-ceph/out/$name.$pid.log
        admin socket = /root/script-ceph/out/$name.$pid.asok
	chdir = ""
	pid file = /root/script-ceph/out/$name.pid
        heartbeat file = /root/script-ceph/out/$name.heartbeat


        debug ms = 1
        mds debug frag = true
        mds debug auth pins = true
        mds debug subtrees = true
        mds data = /root/script-ceph/mds/mds.$id

[osd]

        log file = /root/ceph/src/out/$name.$pid.log
        admin socket = /root/script-ceph/out/$name.$pid.asok
	chdir = ""
	pid file = /root/script-ceph/out/$name.pid
        heartbeat file = /root/script-ceph/out/$name.heartbeat

        osd data = /root/script-ceph/osd/osd$id
        osd journal = /root/script-ceph/osd/osd$id/osd$id.journal
        osd journal size = 100
        osd class tmp = out
        osd class dir = .libs
        osd scrub load threshold = 5.0
        osd debug op order = true
        filestore wbthrottle xfs ios start flusher = 10
        filestore wbthrottle xfs ios hard limit = 20
        filestore wbthrottle xfs inodes hard limit = 30
        filestore wbthrottle btrfs ios start flusher = 10
        filestore wbthrottle btrfs ios hard limit = 20
        filestore wbthrottle btrfs inodes hard limit = 30

        debug ms = 1


[mon]
        mon pg warn min per osd = 3
        mon osd allow primary affinity = true
        mon reweight min pgs per osd = 4

        log file = /root/script-ceph/out/$name.$pid.log
        admin socket = /root/script-ceph/out/$name.$pid.asok
	chdir = ""
	pid file = /root/script-ceph/out/$name.pid
        heartbeat file = /root/script-ceph/out/$name.heartbeat


	debug mon = 10
        debug ms = 1

        mon cluster log file = /root/script-ceph/out/cluster.mon.$id.log
[global]

[mon.a]
        host = n133
        mon data = /root/script-ceph/mon/mon.a
        mon addr = 10.1.0.133:6789
[osd.0]
	public addr = 10.1.0.133
	cluster addr = 10.6.0.133
[osd.1]
	public addr = 10.1.0.133
	cluster addr = 10.6.0.133
[osd.2]
	public addr = 10.1.0.133
	cluster addr = 10.6.0.133
[osd.3]
	public addr = 10.1.0.133
	cluster addr = 10.6.0.133
[osd.4]
	public addr = 10.1.0.133
	cluster addr = 10.6.0.133
[osd.5]
	public addr = 10.1.0.133
	cluster addr = 10.6.0.133
[osd.6]
	public addr = 10.1.0.133
	cluster addr = 10.6.0.133
[osd.7]
	public addr = 10.1.0.134
	cluster addr = 10.6.0.134
[osd.8]
	public addr = 10.1.0.134
	cluster addr = 10.6.0.134
[osd.9]
	public addr = 10.1.0.134
	cluster addr = 10.6.0.134
[osd.10]
	public addr = 10.1.0.134
	cluster addr = 10.6.0.134
[osd.11]
	public addr = 10.1.0.134
	cluster addr = 10.6.0.134
[osd.12]
	public addr = 10.1.0.134
	cluster addr = 10.6.0.134
[osd.13]
	public addr = 10.1.0.134
	cluster addr = 10.6.0.134
[osd.14]
	public addr = 10.1.0.135
	cluster addr = 10.6.0.135
[osd.15]
	public addr = 10.1.0.135
	cluster addr = 10.6.0.135
[osd.16]
	public addr = 10.1.0.135
	cluster addr = 10.6.0.135
[osd.17]
	public addr = 10.1.0.135
	cluster addr = 10.6.0.135
[osd.18]
	public addr = 10.1.0.135
	cluster addr = 10.6.0.135
[osd.19]
	public addr = 10.1.0.135
	cluster addr = 10.6.0.135
[osd.20]
	public addr = 10.1.0.135
	cluster addr = 10.6.0.135
