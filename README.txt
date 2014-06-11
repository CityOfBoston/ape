Many sites run behind Varnish and have a desire for some pages to never expire
and other pages to expire as quickly as every minute. The idea behind this
module is that it provides three main features for controlling the cache-control
header:

1. A secondary cache length that can be used for a list of exception paths.
2. A list of paths that should be excluded from caching by setting the cache
control header to no-cache.
3. Allow cache-control headers for 301 and 302 redirects using drupal_goto to
have individual cache lengths set.

The module also includes rules integration and manipulates the core performance
page a bit so users can find the module's configuration page. Overall it's a
fairly simple module that just manipulates the cache-control header based on
path, and possibly more complex options with Rules.