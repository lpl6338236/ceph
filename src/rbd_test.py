import rados
import rbd_hint
with rados.Rados(conffile='ceph.conf') as cluster:
    with cluster.open_ioctx('rbd') as ioctx:
	print "Before Init"
        rbd_inst = rbd_hint.RBD()
        size = 4 * 1024**3  # 4 GiB
	print "Before Remove"
        rbd_inst.create(ioctx, 'test', size)
	print "After Create"
        with rbd_hint.Image(ioctx, 'test') as image:
		print "Before Write"
        	data = 'foo' * 200
        	image.write_with_hint(data, 0, "osd.1")
		print "After Write"
		str = image.read(0, len(data))
		print str
		image.close()