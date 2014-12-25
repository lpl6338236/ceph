import rados
import rbd_hint
name="test"
with rados.Rados(conffile='ceph.conf') as cluster:
    with cluster.open_ioctx('rbd') as ioctx:
	print "Before Init"
        rbd_inst = rbd_hint.RBD()
        size = 4 * 1024**3  # 4 GiB
	print "Before Remove"
        rbd_inst.create(ioctx, name, size)
	print "After Create"
        with rbd_hint.Image(ioctx, name) as image:
		print "Before Write"
        	data = 'foo' * 200
		image.write_with_hint(data, 0, "n132")
		print "After Write"
		str = image.read_with_hint(0, len(data), "n132")
		print str
		image.close()
