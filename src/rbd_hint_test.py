import rados
import rbd_hint
with rados.Rados(conffile='ceph.conf') as cluster:
    with cluster.open_ioctx('rbd') as ioctx:
        rbd_inst = rbd_hint.RBD()
        size = 4 * 1024**3  # 4 GiB
        rbd_inst.create(ioctx, 'test', size)
        with rbd_hint.Image(ioctx, 'test') as image:
        	data = 'foo' * 200
        	image.write_with_hint(data, 0, "osd.1")
		str = image.read(0, len(data))
		print str
		image.close()
