import rados
import rbd_hint
import sys
name=sys.argv[1]
with rados.Rados(conffile='ceph.conf') as cluster:
    with cluster.open_ioctx('rbd') as ioctx:
	print "Before Init"
        rbd_inst = rbd_hint.RBD()
	rbd_inst.create(ioctx, name, 4*1024**3)
	print "Created"
        with rbd_hint.Image(ioctx, name) as image:
		print "Opened"
		strlen = 0
		for i in range(0, 1):
        		data = 'f' * 64;
			image.write_with_hint(data, strlen,"osd.1")
			print "Writen"
			strlen += len(data)
			print image.read_with_hint(0, strlen, "osd.1")
			print "Read"
		image.close()
	rbd_inst.remove(ioctx, name)
