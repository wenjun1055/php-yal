--TEST--
Check for Yal\Acl\AclInterface
--SKIPIF--
<?php if (!extension_loaded("yal")) print "skip"; ?>
--FILE--
<?php
class AclTest implements Yal\Acl\AclInterface
{
	public function hasResource($role)
	{
		return $role;
	}
	
	public function isAllowed($role, $resource, $privilege)
	{
		return $role;
	}
}
$acl = new AclTest();
var_dump($acl->hasResource("hasResource"));
var_dump($acl->isAllowed("isAllowed", "isAllowed", "isAllowed"));
?>
--EXPECTF--
string(11) "hasResource"
string(9) "isAllowed"