--TEST--
Check for Yal\Acl\Role\Registery
--SKIPIF--
<?php if (!extension_loaded("yal")) print "skip"; ?>
--FILE--
<?php
$genericRole = new Yal\Acl\Role\Registery();
var_dump($genericRole->roles);
var_dump($genericRole->has('id_5'));
?>
--EXPECTF--
array(0) {
}
bool(false)