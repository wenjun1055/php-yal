--TEST--
Check for Yal\Acl\Resource\GenericResource
--SKIPIF--
<?php if (!extension_loaded("yal")) print "skip"; ?>
--FILE--
<?php
$genericResource = new Yal\Acl\Resource\GenericResource('id_5');
var_dump($genericResource->getResourceId());
var_dump($genericResource->__toString());
?>
--EXPECTF--
string(4) "id_5"
string(4) "id_5"