--TEST--
Check for Yal\Acl\Resource\ResourceInterface
--SKIPIF--
<?php if (!extension_loaded("yal")) print "skip"; ?>
--FILE--
<?php
class ResourceInterfaceTest implements Yal\Acl\Resource\ResourceInterface
{
	public function getResourceId()
	{
		return 'getResourceId';
	}
}
$acl = new ResourceInterfaceTest();
var_dump($acl->getResourceId());
?>
--EXPECTF--
string(13) "getResourceId"