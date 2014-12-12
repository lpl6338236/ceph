[global]
        fsid = 9f82eb35-1bf6-4c27-8a28-efd62c681aa5
        osd pg bits = 3
        osd pgp bits = 5  ; (invalid, but ceph should cope!)
        osd crush chooseleaf type = 0
        osd pool default min size = 1
        osd pool default hint size = 6
        osd failsafe full ratio = .99
        mon osd full ratio = .99
        mon data avail warn = 10
        mon data avail crit = 1
        osd pool default erasure code directory = .libs
        osd pool default erasure code profile = plugin=jerasure technique=reed_sol_van k=2 m=1 ruleset-failure-domain=osd
        rgw frontends = fastcgi, civetweb port=8000
        filestore fd cache size = 32
        run dir = /home/fedora/tmpceph/out
        auth supported = cephx

[client]
        keyring = /home/fedora/tmpceph/ceph.client.admin.keyring
        log file = /home/fedora/tmpceph/out/$name.$pid.log
        admin socket = /home/fedora/tmpceph/out/$name.$pid.asok

[mds]

        log file = /home/fedora/tmpceph/out/$name.$pid.log
        admin socket = /home/fedora/tmpceph/out/$name.$pid.asok
	chdir = ""
	pid file = /home/fedora/tmpceph/out/$name.pid
        heartbeat file = /home/fedora/tmpceph/out/$name.heartbeat


        debug ms = 1
        mds debug frag = true
        mds debug auth pins = true
        mds debug subtrees = true
        mds data = /home/fedora/tmpceph/mds/mds.$id

[osd]

        log file = /home/fedora/tmpceph/out/$name.$pid.log
        admin socket = /home/fedora/tmpceph/out/$name.$pid.asok
	chdir = ""
	pid file = /home/fedora/tmpceph/out/$name.pid
        heartbeat file = /home/fedora/tmpceph/out/$name.heartbeat

        osd data = /home/fedora/tmpceph/osd/osd$id
        osd journal = /home/fedora/tmpceph/osd/osd$id.journal
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

        log file = /home/fedora/tmpceph/out/$name.$pid.log
        admin socket = /home/fedora/tmpceph/out/$name.$pid.asok
	chdir = ""
	pid file = /home/fedora/tmpceph/out/$name.pid
        heartbeat file = /home/fedora/tmpceph/out/$name.heartbeat


	debug mon = 10
        debug ms = 1

        mon cluster log file = /home/fedora/tmpceph/out/cluster.mon.$id.log
[global]

[mon.a]
        host = ceps-build
        mon data = /home/fedora/tmpceph/mon/mon.a
        mon addr = 127.0.0.1:6789
[osd.0]
        host = ceps-build
[osd.1]
        host = ceps-build
[osd.2]
        host = ceps-build
[mds.a]
        host = ceps-build
[mds.b]
        host = ceps-build
[mds.c]
        host = ceps-build
