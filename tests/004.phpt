--TEST--
Check for Yal\Acl\Role\GenericRole
--SKIPIF--
<?php if (!extension_loaded("yal")) print "skip"; ?>
--FILE--
<?php
$genericRole = new Yal\Acl\Role\GenericRole('id_5');
var_dump($genericRole->getRoleId());
var_dump($genericRole->__toString());
?>
--EXPECTF--
string(4) "id_5"
string(4) "id_5"