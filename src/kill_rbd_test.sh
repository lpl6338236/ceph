#!/bin/sh
kill `ps -ef|grep rbd_test|awk '{print $2}'`
