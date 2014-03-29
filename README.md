CONTENTS OF THIS FILE
---------------------

 * summary
 * requirements
 * installation
 * configuration
 * troubleshooting
 * sponsors

SUMMARY
-------

Islandora Entity Bridge provides a simple connector between Islandora/Fedora
Entities and Drupal. It is to allow for referencing Islandora Objects (like
in Flag, Entity Queue, Entityreference, etc) without bringing in the full
weight of an Entity like Node.

For true syncing of content to bring over from Fedora into Drupal (as nodes), see the
Islandora Sync(https://github.com/islandora/islandora_sync) module.

REQUIREMENTS
------------

Islandora

Entity

INSTALLATION
------------

Download and enable module.

CONFIGURATION
-------------

Right now, all types of Fedora Objects are brought over. This brings in their
pid, label, content model, status to start.

Display configuration is currently a work in progress as I try to figure out
a way to use the field display UI without the Islandora Entity Bridge necessarily
having fields. As such the current display configuration is unreliable.
However, there is views integration with three different field
handlers: datastream link, image display of datastreams, and datastream xpath.

The xpath datastream field handler requires a full xpath (with the namespaces).
This needs to be worked out so it is hopefully as simple as with Islandora Sync.

TROUBLESHOOTING
---------------

Use the issue queue!

FAQ
---

Why the alternative?

First, we need to get the history lesson on why both these modules exist.
Directly using Islandora Entities with other Drupal modules is not possible. 
In Drupal, entities are defined as having Integer IDs. Since fedora records
do not necessarily have numeric PIDs, a large chunk of the drupal ecosystem
(Flag, Entityreference, Entityqueue, Views to name a few) are not directly
accessible. A chunk of the blame falls on Drupal Core for the restriction.
But that is a long process and requires changing core and various contributed
modules.

Hence the excellent Islandora Sync module was created thanks to DGI and UCLA.

Currently, Islandora Sync feeds various pieces of data from all objects of a
content model into Drupal. This means that fields (namely, object assets) get
duplicated. And if you are dealing with a DAMS with hundreds of thousands of
objects, Drupal performance can become somewhat hard to manage (especially if
using the database field storage for nodes).

The (initial) goal of Islandora Entity Bridge is to provide a few key columns
of data (from the Fedora Model: pid, label, content model, status) to Drupal.
These get mapped to an Integer ID which allows for interfacing with various
other "Drupal" modules like Flag, Entityreference, Entityqueue, etc. Everything
else remains in (and gets referenced from) Fedora via Islandora APIs. While all
hundreds of thousands of records will get synced, the dataset/index would still
remain small enough to not be a large burden on Drupal (and there is no
duplication of the data in the datastreams).

With that said, Islandora Sync offers less end-configuration (while the
integration is starting to get in place, views are much easier to work with,
for once.). Theming in IEB is nowhere near ready (and really needs to be
thought out) while Islandora Sync is quite magical on that front.

TLDR: both modules have their places :)

SPONSORS
--------

Cherry Hill
