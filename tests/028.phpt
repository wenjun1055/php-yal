--TEST--
testResourceInheritsNonExistent

Check for Yal\Acl\Acl::inheritsResource(
                Resource\ResourceInterface|string    $resource
                Resource\ResourceInterface|string    inherit
                bool                                 $onlyParent )
--SKIPIF--
<?php if (!extension_loaded("yal")) print "skip"; ?>
--FILE--
<?php
namespace Yal\Acl;

$acl = new Acl();
$resourceArea = new Resource\GenericResource('area');
$acl->addResource($resourceArea);

$acl->inheritsResource('nonexistent', $resourceArea);

?>
--EXPECTF--