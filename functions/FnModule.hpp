// Auto-generated by compile-delayed-module from ../src/functions/FnModule.xq
// DO NOT EDIT

// ../src/functions/FnModule.xq
static const XMLCh fn_file[] = { 46, 46, 47, 115, 114, 99, 47, 102, 117, 110, 99, 116, 105, 111, 110, 115, 47, 70, 110, 77, 111, 100, 117, 108, 101, 46, 120, 113, 0 };

// fn
static const XMLCh fn_prefix[] = { 102, 110, 0 };

// http://www.w3.org/2005/xpath-functions
static const XMLCh fn_uri[] = { 104, 116, 116, 112, 58, 47, 47, 119, 119, 119, 46, 119, 51, 46, 111, 114, 103, 47, 50, 48, 48, 53, 47, 120, 112, 97, 116, 104, 45, 102, 117, 110, 99, 116, 105, 111, 110, 115, 0 };

static const DelayedModule::FuncDef fn_functions[] = {
  {
    "data", 1, false, 20, 1,
    "declare function data($a as item()*) as xs:anyAtomicType*\n"
    "{\n"
    "  $a\n"
    "}\n"
  },
  {
    "string-join", 1, false, 28, 1,
    "declare function string-join($seq as xs:string*) as xs:string\n"
    "{\n"
    "  string-join($seq, \"\")\n"
    "}\n"
  },
  {
    "string-join", 2, false, 33, 1,
    "declare function string-join($seq as xs:string*, $join as xs:string) as xs:string\n"
    "{\n"
    "  if(empty($seq)) then \"\"\n"
    "  else string-join-helper($seq, $join)\n"
    "}\n"
  },
  {
    "string-join-helper", 2, true, 39, 1,
    "declare private function string-join-helper($seq as xs:string*, $join as xs:string) as xs:string\n"
    "{\n"
    "  if(empty(tail($seq))) then head($seq)\n"
    "  else concat(head($seq), $join, string-join-helper(tail($seq), $join))\n"
    "}\n"
  },
  {
    "substring-before", 2, false, 45, 1,
    "declare function substring-before($arg1 as xs:string?, $arg2 as xs:string?) as xs:string\n"
    "{\n"
    "  substring-before($arg1, $arg2, default-collation())\n"
    "}\n"
  },
  {
    "substring-before", 3, false, 50, 1,
    "declare function substring-before($arg1 as xs:string?, $arg2 as xs:string?, $collation as xs:string)\n"
    "  as xs:string\n"
    "{\n"
    "  let $arg1 := if(empty($arg1)) then \"\" else $arg1\n"
    "  let $arg2 := if(empty($arg2)) then \"\" else $arg2\n"
    "  let $arg2len := string-length($arg2)\n"
    "  return\n"
    "    substring($arg1, 1,\n"
    "      string-index-of($arg1, 1, 1 + string-length($arg1) - $arg2len, $arg2, $arg2len, $collation) - 1)\n"
    "}\n"
  },
  {
    "substring-after", 2, false, 61, 1,
    "declare function substring-after($arg1 as xs:string?, $arg2 as xs:string?) as xs:string\n"
    "{\n"
    "  substring-after($arg1, $arg2, default-collation())\n"
    "}\n"
  },
  {
    "substring-after", 3, false, 66, 1,
    "declare function substring-after($arg1 as xs:string?, $arg2 as xs:string?, $collation as xs:string)\n"
    "  as xs:string\n"
    "{\n"
    "  let $arg1 := if(empty($arg1)) then \"\" else $arg1\n"
    "  let $arg2 := if(empty($arg2)) then \"\" else $arg2\n"
    "  let $arg2len := string-length($arg2)\n"
    "  let $index := string-index-of($arg1, 1, 1 + string-length($arg1) - $arg2len, $arg2, $arg2len, $collation)\n"
    "  return\n"
    "    if($index eq 0) then \"\" else substring($arg1, $index + $arg2len)\n"
    "}\n"
  },
  {
    "string-index-of", 6, true, 77, 1,
    "declare private function string-index-of($str as xs:string, $index as xs:decimal, $endindex as xs:decimal,\n"
    "  $tofind as xs:string, $tofindlen as xs:decimal, $collation as xs:string) as xs:decimal\n"
    "{\n"
    "  if($index gt $endindex) then 0\n"
    "  else if(compare($tofind, substring($str, $index, $tofindlen), $collation) eq 0) then $index\n"
    "  else string-index-of($str, $index + 1, $endindex, $tofind, $tofindlen, $collation)\n"
    "}\n"
  },
  {
    "codepoint-equal", 2, false, 85, 1,
    "declare function codepoint-equal($arg1 as xs:string?, $arg2 as xs:string?) as xs:boolean?\n"
    "{\n"
    "  compare($arg1, $arg2, \"http://www.w3.org/2005/xpath-functions/collation/codepoint\") eq 0\n"
    "}\n"
  },
  {
    "translate", 3, false, 90, 1,
    "declare function translate($arg as xs:string?, $mapString as xs:string, $transString as xs:string) as xs:string\n"
    "{\n"
    "  codepoints-to-string(\n"
    "    let $in := string-to-codepoints($arg)\n"
    "    let $map := string-to-codepoints($mapString)\n"
    "    let $trans := string-to-codepoints($transString)\n"
    "    for $c in $in\n"
    "    let $index := head(index-of($map, $c))\n"
    "    return\n"
    "      if(empty($index)) then $c else $trans[$index]\n"
    "  )\n"
    "}\n"
  },
  {
    "codepoint-in-utf8", 1, true, 103, 1,
    "declare private function codepoint-in-utf8($c as xs:integer) as xs:integer+\n"
    "{\n"
    "  if($c < 128) then $c\n"
    "  else if($c < 2048) then (\n"
    "    ($c idiv 64) + 192,\n"
    "    ($c mod 64) + 128\n"
    "  )\n"
    "  else if($c < 65536) then (\n"
    "    ($c idiv 4096) + 224,\n"
    "    (($c idiv 64) mod 64) + 128,\n"
    "    ($c mod 64) + 128\n"
    "  )\n"
    "  else (\n"
    "    ($c idiv 262144) + 240,\n"
    "    (($c idiv 4096) mod 64) + 128,\n"
    "    (($c idiv 64) mod 64) + 128,\n"
    "    ($c mod 64) + 128\n"
    "  )\n"
    "}\n"
  },
  {
    "percent-encode", 1, true, 123, 1,
    "declare private function percent-encode($c as xs:integer) as xs:integer+\n"
    "{\n"
    "  (: Codepoint for \"%\" :)\n"
    "  let $percent := 37\n"
    "  (: Codepoints for \"0\" - \"9\", \"A\" - \"F\" :)\n"
    "  let $hex := (48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 65, 66, 67, 68, 69, 70)\n"
    "  for $byte in codepoint-in-utf8($c)\n"
    "  return (\n"
    "    $percent,\n"
    "    $hex[($byte idiv 16) + 1],\n"
    "    $hex[($byte mod 16) + 1]\n"
    "  )\n"
    "}\n"
  },
  {
    "encode-for-uri", 1, false, 137, 1,
    "declare function encode-for-uri($uri-part as xs:string?) as xs:string\n"
    "{\n"
    "  codepoints-to-string(\n"
    "    let $A := string-to-codepoints(\"A\")\n"
    "    let $Z := string-to-codepoints(\"Z\")\n"
    "    let $a := string-to-codepoints(\"a\")\n"
    "    let $z := string-to-codepoints(\"z\")\n"
    "    let $d0 := string-to-codepoints(\"0\")\n"
    "    let $d9 := string-to-codepoints(\"9\")\n"
    "    let $hyphen := string-to-codepoints(\"-\")\n"
    "    let $underscore := string-to-codepoints(\"_\")\n"
    "    let $fullstop := string-to-codepoints(\".\")\n"
    "    let $tilde := string-to-codepoints(\"~\")\n"
    "\n"
    "    for $c in string-to-codepoints($uri-part)\n"
    "    return\n"
    "      if(($c ge $A and $c le $Z) or\n"
    "        ($c ge $a and $c le $z) or\n"
    "        ($c ge $d0 and $c le $d9) or\n"
    "        $c eq $hyphen or $c eq $underscore or\n"
    "        $c eq $fullstop or $c eq $tilde)\n"
    "      then $c\n"
    "      else percent-encode($c)\n"
    "  )\n"
    "}\n"
  },
  {
    "iri-to-uri", 1, false, 163, 1,
    "declare function iri-to-uri($iri as xs:string?) as xs:string\n"
    "{\n"
    "  codepoints-to-string(\n"
    "    let $leftangle := string-to-codepoints(\"<\")\n"
    "    let $rightangle := string-to-codepoints(\">\")\n"
    "    let $doublequote := string-to-codepoints('\"')\n"
    "    let $space := string-to-codepoints(\" \")\n"
    "    let $leftcurly := string-to-codepoints(\"{\")\n"
    "    let $rightcurly := string-to-codepoints(\"}\")\n"
    "    let $bar := string-to-codepoints(\"|\")\n"
    "    let $backslash := 92\n"
    "    let $hat := string-to-codepoints(\"^\")\n"
    "    let $backtick := string-to-codepoints(\"`\")\n"
    "\n"
    "    for $c in string-to-codepoints($iri)\n"
    "    return\n"
    "      if($c lt 32 or $c gt 126 or\n"
    "        $c eq $leftangle or $c eq $rightangle or\n"
    "        $c eq $doublequote or $c eq $space or\n"
    "        $c eq $leftcurly or $c eq $rightcurly or\n"
    "        $c eq $bar or $c eq $backslash or\n"
    "        $c eq $hat or $c eq $backtick)\n"
    "      then percent-encode($c)\n"
    "      else $c\n"
    "  )\n"
    "}\n"
  },
  {
    "escape-html-uri", 1, false, 190, 1,
    "declare function escape-html-uri($iri as xs:string?) as xs:string\n"
    "{\n"
    "  codepoints-to-string(\n"
    "    for $c in string-to-codepoints($iri)\n"
    "    return\n"
    "      if($c lt 32 or $c gt 126)\n"
    "      then percent-encode($c)\n"
    "      else $c\n"
    "  )\n"
    "}\n"
  },
  {
    "resolve-QName", 2, false, 204, 1,
    "declare function resolve-QName($qname as xs:string?, $element as element()) as xs:QName?\n"
    "{\n"
    "  typeswitch($qname)\n"
    "  case $qname as xs:string return\n"
    "    let $mock := QName(\"dummy\", $qname)\n"
    "    let $uri := namespace-uri-for-prefix(prefix-from-QName($mock), $element)\n"
    "    return\n"
    "      if(empty(prefix-from-QName($mock)) or exists($uri)) then QName($uri, $qname)\n"
    "      else error(xs:QName(\"err:FONS0004\"), concat(\"No namespace found for prefix: \"\"\", prefix-from-QName($mock), \"\"\"\"))\n"
    "  default return ()\n"
    "}\n"
  },
  {
    "namespace-uri-for-prefix", 2, false, 216, 1,
    "declare function namespace-uri-for-prefix($prefix as xs:string?, $element as element()) as xs:anyURI?\n"
    "{\n"
    "  let $prefix := if(empty($prefix)) then \"\" else $prefix\n"
    "  return $element/namespace::*[name() eq $prefix]/xs:anyURI(.)\n"
    "}\n"
  },
  {
    "in-scope-prefixes", 1, false, 222, 1,
    "declare function in-scope-prefixes($element as element()) as xs:string*\n"
    "{\n"
    "  $element/namespace::*/name()\n"
    "}\n"
  },
  {
    "true", 0, false, 230, 1,
    "declare function true() as xs:boolean\n"
    "{\n"
    "  xs:boolean(\"1\")\n"
    "}\n"
  },
  {
    "false", 0, false, 235, 1,
    "declare function false() as xs:boolean\n"
    "{\n"
    "  xs:boolean(\"0\")\n"
    "}\n"
  },
  {
    "boolean", 1, false, 240, 1,
    "declare function boolean($arg as item()*) as xs:boolean\n"
    "{\n"
    "  $arg and true()\n"
    "}\n"
  },
  {
    "exists", 1, false, 245, 1,
    "declare function exists($arg as item()*) as xs:boolean\n"
    "{\n"
    "  not(empty($arg))\n"
    "}\n"
  },
  {
    "zero-or-one", 1, false, 253, 1,
    "declare function zero-or-one($arg as item()*) as item()?\n"
    "{\n"
    "  typeswitch($arg)\n"
    "  case $arg_ as item()? return $arg_\n"
    "  default return error(xs:QName(\"err:FORG0003\"), \"Sequence contains more then one item\")\n"
    "}\n"
  },
  {
    "one-or-more", 1, false, 260, 1,
    "declare function one-or-more($arg as item()*) as item()+\n"
    "{\n"
    "  typeswitch($arg)\n"
    "  case $arg_ as item()+ return $arg_\n"
    "  default return error(xs:QName(\"err:FORG0004\"), \"Sequence is empty\")\n"
    "}\n"
  },
  {
    "exactly-one", 1, false, 267, 1,
    "declare function exactly-one($arg as item()*) as item()\n"
    "{\n"
    "  typeswitch($arg)\n"
    "  case $arg_ as item() return $arg_\n"
    "  case empty-sequence() return error(xs:QName(\"err:FORG0005\"), \"Sequence is empty\")\n"
    "  default return error(xs:QName(\"err:FORG0005\"), \"Sequence contains more then one item\")\n"
    "}\n"
  },
  {
    "index-of", 2, false, 275, 1,
    "declare function index-of($seq as xs:anyAtomicType*, $search as xs:anyAtomicType) as xs:integer*\n"
    "{\n"
    "  (: Check for NaN :)\n"
    "  if($search ne $search) then () else index-of-helper($seq, $search, default-collation())\n"
    "}\n"
  },
  {
    "index-of", 3, false, 281, 1,
    "declare function index-of($seq as xs:anyAtomicType*, $search as xs:anyAtomicType,\n"
    "   $collation as xs:string) as xs:integer*\n"
    "{\n"
    "  (: Check for NaN :)\n"
    "  if($search ne $search) then () else index-of-helper($seq, $search, $collation)\n"
    "}\n"
  },
  {
    "index-of-helper", 3, true, 288, 1,
    "declare private function index-of-helper($seq as xs:anyAtomicType*, $search as xs:anyAtomicType,\n"
    "  $collation as xs:string) as xs:integer*\n"
    "{\n"
    "  for $s at $p in $seq\n"
    "  where empty(tail(distinct-values(($s, $search), $collation)))\n"
    "  return $p\n"
    "}\n"
  },
  {
    "insert-before", 3, false, 296, 1,
    "declare function insert-before($target as item()*, $position as xs:integer, $inserts as item()*)\n"
    "  as item()*\n"
    "{\n"
    "  if($position le 1 or empty($inserts)) then ($inserts, $target)\n"
    "  else (head($target), insert-before(tail($target), $position - 1, $inserts))\n"
    "}\n"
  },
  {
    "remove", 2, false, 303, 1,
    "declare function remove($target as item()*, $position as xs:integer) as item()*\n"
    "{\n"
    "  $target[position() ne $position]\n"
    "}\n"
  },
  {
    "reverse", 1, false, 308, 1,
    "declare function reverse($seq as item()*) as item()*\n"
    "{\n"
    "  if(empty($seq)) then ()\n"
    "  else (reverse(tail($seq)), head($seq))\n"
    "}\n"
  },
  {
    "subsequence", 2, false, 314, 1,
    "declare function subsequence($sourceSeq as item()*, $startingLoc as xs:double) as item()*\n"
    "{\n"
    "  let $s := round($startingLoc)\n"
    "  return\n"
    "    if($s < 1) then $sourceSeq\n"
    "    else xqilla:drop($sourceSeq, $s - 1)\n"
    "}\n"
  },
  {
    "subsequence", 3, false, 322, 1,
    "declare function subsequence($sourceSeq as item()*, $startingLoc as xs:double,\n"
    "  $length as xs:double) as item()*\n"
    "{\n"
    "  let $s := round($startingLoc)\n"
    "  return\n"
    "    if($s < 1) then take($sourceSeq, round($length) + $s - 1)\n"
    "    else take(xqilla:drop($sourceSeq, $s - 1), round($length))\n"
    "}\n"
  },
  {
    "take", 2, true, 331, 1,
    "declare private function take($seq as item()*, $num as xs:double) as item()*\n"
    "{\n"
    "  if($num le 0 or empty($seq)) then ()\n"
    "  else (head($seq), take(tail($seq), $num - 1))\n"
    "}\n"
  },
  {
    "deep-equal", 2, false, 337, 1,
    "declare function deep-equal($parameter1 as item()*, $parameter2 as item()*) as xs:boolean\n"
    "{\n"
    "  deep-equal($parameter1, $parameter2, default-collation())\n"
    "}\n"
  },
  {
    "deep-equal", 3, false, 342, 1,
    "declare function deep-equal($p1 as item()*, $p2 as item()*, $collation as xs:string) as xs:boolean\n"
    "{\n"
    "  if(empty($p1)) then empty($p2) else\n"
    "  if(empty($p2)) then false() else\n"
    "\n"
    "  let $i1 := head($p1), $i2 := head($p2)\n"
    "  return\n"
    "    typeswitch($i1)\n"
    "\n"
    "    case $a1 as xs:anyAtomicType return\n"
    "      typeswitch($i2)\n"
    "      case $a2 as xs:anyAtomicType return\n"
    "        empty(tail(distinct-values(($a1, $a2), $collation))) and\n"
    "        deep-equal(tail($p1), tail($p2), $collation)\n"
    "      case node() return false()\n"
    "      default return deep-equal-error()\n"
    "\n"
    "    case $n1 as node() return (\n"
    "      typeswitch($i2)\n"
    "      case xs:anyAtomicType return false()\n"
    "      case $n2 as node() return (\n"
    "        deep-equal-nodes($n1, $n2, $collation) and\n"
    "        deep-equal(tail($p1), tail($p2), $collation)\n"
    "      )\n"
    "      default return deep-equal-error()\n"
    "    )\n"
    "\n"
    "    default return deep-equal-error()\n"
    "}\n"
  },
  {
    "deep-equal-error", 0, true, 372, 1,
    "declare private function deep-equal-error()\n"
    "{\n"
    "  error(xs:QName(\"err:FOTY0015\"), \"An argument to fn:deep-equal() contains a function item\")\n"
    "}\n"
  },
  {
    "deep-equal-nodes", 3, true, 377, 1,
    "declare private function deep-equal-nodes($p1 as node()*, $p2 as node()*, $collation as xs:string) as xs:boolean\n"
    "{\n"
    "  if(empty($p1)) then empty($p2) else\n"
    "  if(empty($p2)) then false() else\n"
    "\n"
    "  let $i1 := head($p1), $i2 := head($p2)\n"
    "  return\n"
    "  typeswitch($i1)\n"
    "\n"
    "  case document-node() return\n"
    "    typeswitch($i2)\n"
    "    case document-node() return\n"
    "      deep-equal-nodes($i1/(*|text()), $i2/(*|text()), $collation) and\n"
    "      deep-equal-nodes(tail($p1), tail($p2), $collation)\n"
    "    default return false()\n"
    "\n"
    "  case text() return\n"
    "    typeswitch($i2)\n"
    "    case text() return\n"
    "      empty(tail(distinct-values(($i1, $i2), $collation))) and\n"
    "      deep-equal-nodes(tail($p1), tail($p2), $collation)\n"
    "    default return false()\n"
    "\n"
    "  case comment() return\n"
    "    typeswitch($i2)\n"
    "    case comment() return\n"
    "      empty(tail(distinct-values(($i1, $i2), $collation))) and\n"
    "      deep-equal-nodes(tail($p1), tail($p2), $collation)\n"
    "    default return false()\n"
    "\n"
    "  case processing-instruction() return\n"
    "    typeswitch($i2)\n"
    "    case processing-instruction() return\n"
    "      node-name($i1) eq node-name($i2) and\n"
    "      empty(tail(distinct-values(($i1, $i2), $collation))) and\n"
    "      deep-equal-nodes(tail($p1), tail($p2), $collation)\n"
    "    default return false()\n"
    "\n"
    "  case attribute() return\n"
    "    typeswitch($i2)\n"
    "    case attribute() return\n"
    "      node-name($i1) eq node-name($i2) and\n"
    "      deep-equal(data($i1), data($i2), $collation) and\n"
    "      deep-equal-nodes(tail($p1), tail($p2), $collation)\n"
    "    default return false()\n"
    "\n"
    "  case element() return\n"
    "    typeswitch($i2)\n"
    "    case element() return (\n"
    "      node-name($i1) eq node-name($i2) and\n"
    "      count($i1/@*) eq count($i2/@*) and\n"
    "      (every $a1 in $i1/@* satisfies\n"
    "        some $a2 in $i2/@* satisfies deep-equal-nodes($a1, $a2, $collation)) and\n"
    "\n"
    "      (if(empty($i1/*) and empty($i2/*))\n"
    "        then deep-equal(data($i1), data($i2), $collation)\n"
    "        else deep-equal-nodes($i1/(*|text()), $i2/(*|text()), $collation)) and\n"
    "\n"
    "      deep-equal-nodes(tail($p1), tail($p2), $collation)\n"
    "    )\n"
    "    default return false()\n"
    "\n"
    "  \n"
    "  default (: namespace-node() :) return\n"
    "    typeswitch($i2)\n"
    "    case namespace-node() return\n"
    "      deep-equal(node-name($i1), node-name($i2), $collation) and\n"
    "      codepoint-equal($i1, $i2) and\n"
    "      deep-equal-nodes(tail($p1), tail($p2), $collation)\n"
    "    default return false()\n"
    "}\n"
  },
  {
    "avg", 1, false, 452, 1,
    "declare function avg($arg as xs:anyAtomicType*) as xs:anyAtomicType?\n"
    "{\n"
    "  sum($arg, ()) div count($arg)\n"
    "}\n"
  },
  {
    "sum", 1, false, 457, 1,
    "declare function sum($arg as xs:anyAtomicType*) as xs:anyAtomicType\n"
    "{\n"
    "  sum($arg, 0)\n"
    "}\n"
  },
  {
    "sum", 2, false, 462, 1,
    "declare function sum($arg as xs:anyAtomicType*, $zero as xs:anyAtomicType?) as xs:anyAtomicType?\n"
    "{\n"
    "  typeswitch(head($arg))\n"
    "  case empty-sequence() return $zero\n"
    "  case $head as xs:untypedAtomic return numeric-sum(tail($arg), xs:double($head))\n"
    "  case $head as xs:double | xs:float | xs:decimal return\n"
    "    if($head ne $head) then $head else numeric-sum(tail($arg), $head)\n"
    "  case $head as xs:yearMonthDuration return yearMonthDuration-sum(tail($arg), $head)\n"
    "  case $head as xs:dayTimeDuration return dayTimeDuration-sum(tail($arg), $head)\n"
    "  default return error(xs:QName(\"err:FORG0006\"), \"Invalid argument to fn:sum() function\")\n"
    "}\n"
  },
  {
    "numeric-sum", 2, true, 474, 1,
    "declare private function numeric-sum($arg as xs:anyAtomicType*, $result as xs:anyAtomicType) as xs:anyAtomicType\n"
    "{\n"
    "  typeswitch(head($arg))\n"
    "  case empty-sequence() return $result\n"
    "  case $head as xs:untypedAtomic return numeric-sum(tail($arg), xs:double($head) + $result)\n"
    "  case $head as xs:double | xs:float | xs:decimal return\n"
    "    if($head ne $head) then $head else numeric-sum(tail($arg), $head + $result)\n"
    "  default return error(xs:QName(\"err:FORG0006\"), \"Invalid argument to fn:sum() function\")\n"
    "}\n"
  },
  {
    "yearMonthDuration-sum", 2, true, 484, 1,
    "declare private function yearMonthDuration-sum($arg as xs:anyAtomicType*, $result as xs:yearMonthDuration) as xs:yearMonthDuration\n"
    "{\n"
    "  typeswitch(head($arg))\n"
    "  case empty-sequence() return $result\n"
    "  case $head as xs:yearMonthDuration return yearMonthDuration-sum(tail($arg), $head + $result)\n"
    "  default return error(xs:QName(\"err:FORG0006\"), \"Invalid argument to fn:sum() function\")\n"
    "}\n"
  },
  {
    "dayTimeDuration-sum", 2, true, 492, 1,
    "declare private function dayTimeDuration-sum($arg as xs:anyAtomicType*, $result as xs:dayTimeDuration) as xs:dayTimeDuration\n"
    "{\n"
    "  typeswitch(head($arg))\n"
    "  case empty-sequence() return $result\n"
    "  case $head as xs:dayTimeDuration return dayTimeDuration-sum(tail($arg), $head + $result)\n"
    "  default return error(xs:QName(\"err:FORG0006\"), \"Invalid argument to fn:sum() function\")\n"
    "}\n"
  },
  {
    "max", 1, false, 500, 1,
    "declare function max($arg as xs:anyAtomicType*) as xs:anyAtomicType?\n"
    "{\n"
    "  max($arg, default-collation())\n"
    "}\n"
  },
  {
    "max", 2, false, 505, 1,
    "declare function max($arg as xs:anyAtomicType*, $collation as xs:string) as xs:anyAtomicType?\n"
    "{\n"
    "  typeswitch(head($arg))\n"
    "  case empty-sequence() return ()\n"
    "  case $head as xs:untypedAtomic | xs:double return double-max(tail($arg), xs:double($head))\n"
    "  case $head as xs:float return float-max(tail($arg), $head)\n"
    "  case $head as xs:decimal return decimal-max(tail($arg), $head)\n"
    "  case $head as xs:anyURI | xs:string return string-max(tail($arg), xs:string($head), $collation)\n"
    "  case $head as xs:boolean return boolean-max(tail($arg), $head)\n"
    "  case $head as xs:date return date-max(tail($arg), $head)\n"
    "  case $head as xs:time return time-max(tail($arg), $head)\n"
    "  case $head as xs:dateTime return dateTime-max(tail($arg), $head)\n"
    "  case $head as xs:yearMonthDuration return yearMonthDuration-max(tail($arg), $head)\n"
    "  case $head as xs:dayTimeDuration return dayTimeDuration-max(tail($arg), $head)\n"
    "  default return error(xs:QName(\"err:FORG0006\"), \"Uncomparable items in argument to fn:max() function\")\n"
    "}\n"
  },
  {
    "double-max", 2, true, 522, 1,
    "declare private function double-max($arg as xs:anyAtomicType*, $result as xs:double) as xs:double\n"
    "{\n"
    "  typeswitch(head($arg))\n"
    "  case empty-sequence() return $result\n"
    "  case $head as xs:untypedAtomic | xs:double | xs:float | xs:decimal return\n"
    "    let $head := xs:double($head) return\n"
    "      double-max(tail($arg), if($head gt $result or $head ne $head) then $head else $result)\n"
    "  default return error(xs:QName(\"err:FORG0006\"), \"Uncomparable items in argument to fn:max() function\")\n"
    "}\n"
  },
  {
    "float-max", 2, true, 532, 1,
    "declare private function float-max($arg as xs:anyAtomicType*, $result as xs:float) as xs:anyAtomicType\n"
    "{\n"
    "  typeswitch(head($arg))\n"
    "  case empty-sequence() return $result\n"
    "  case $head as xs:untypedAtomic | xs:double return double-max($arg, xs:double($result))\n"
    "  case $head as xs:float | xs:decimal return\n"
    "    let $head := xs:float($head) return\n"
    "      float-max(tail($arg), if($head gt $result or $head ne $head) then $head else $result)\n"
    "  default return error(xs:QName(\"err:FORG0006\"), \"Uncomparable items in argument to fn:max() function\")\n"
    "}\n"
  },
  {
    "decimal-max", 2, true, 543, 1,
    "declare private function decimal-max($arg as xs:anyAtomicType*, $result as xs:decimal) as xs:anyAtomicType\n"
    "{\n"
    "  typeswitch(head($arg))\n"
    "  case empty-sequence() return $result\n"
    "  case $head as xs:untypedAtomic | xs:double return double-max($arg, xs:double($result))\n"
    "  case $head as xs:float return float-max($arg, xs:float($result))\n"
    "  case $head as xs:decimal return decimal-max(tail($arg), if($head gt $result) then $head else $result)\n"
    "  default return error(xs:QName(\"err:FORG0006\"), \"Uncomparable items in argument to fn:max() function\")\n"
    "}\n"
  },
  {
    "string-max", 3, true, 553, 1,
    "declare private function string-max($arg as xs:anyAtomicType*, $result as xs:string, $collation as xs:string) as xs:string\n"
    "{\n"
    "  typeswitch(head($arg))\n"
    "  case empty-sequence() return $result\n"
    "  case $head as xs:string | xs:anyURI return\n"
    "    string-max(tail($arg), if(compare($head, $result, $collation) gt 0) then xs:string($head) else $result, $collation)\n"
    "  default return error(xs:QName(\"err:FORG0006\"), \"Uncomparable items in argument to fn:max() function\")\n"
    "}\n"
  },
  {
    "boolean-max", 2, true, 562, 1,
    "declare private function boolean-max($arg as xs:anyAtomicType*, $result as xs:boolean) as xs:boolean\n"
    "{\n"
    "  typeswitch(head($arg))\n"
    "  case empty-sequence() return $result\n"
    "  case $head as xs:boolean return boolean-max(tail($arg), if($head gt $result) then $head else $result)\n"
    "  default return error(xs:QName(\"err:FORG0006\"), \"Uncomparable items in argument to fn:max() function\")\n"
    "}\n"
  },
  {
    "date-max", 2, true, 570, 1,
    "declare private function date-max($arg as xs:anyAtomicType*, $result as xs:date) as xs:date\n"
    "{\n"
    "  typeswitch(head($arg))\n"
    "  case empty-sequence() return $result\n"
    "  case $head as xs:date return date-max(tail($arg), if($head gt $result) then $head else $result)\n"
    "  default return error(xs:QName(\"err:FORG0006\"), \"Uncomparable items in argument to fn:max() function\")\n"
    "}\n"
  },
  {
    "time-max", 2, true, 578, 1,
    "declare private function time-max($arg as xs:anyAtomicType*, $result as xs:time) as xs:time\n"
    "{\n"
    "  typeswitch(head($arg))\n"
    "  case empty-sequence() return $result\n"
    "  case $head as xs:time return time-max(tail($arg), if($head gt $result) then $head else $result)\n"
    "  default return error(xs:QName(\"err:FORG0006\"), \"Uncomparable items in argument to fn:max() function\")\n"
    "}\n"
  },
  {
    "dateTime-max", 2, true, 586, 1,
    "declare private function dateTime-max($arg as xs:anyAtomicType*, $result as xs:dateTime) as xs:dateTime\n"
    "{\n"
    "  typeswitch(head($arg))\n"
    "  case empty-sequence() return $result\n"
    "  case $head as xs:dateTime return dateTime-max(tail($arg), if($head gt $result) then $head else $result)\n"
    "  default return error(xs:QName(\"err:FORG0006\"), \"Uncomparable items in argument to fn:max() function\")\n"
    "}\n"
  },
  {
    "yearMonthDuration-max", 2, true, 594, 1,
    "declare private function yearMonthDuration-max($arg as xs:anyAtomicType*, $result as xs:yearMonthDuration) as xs:yearMonthDuration\n"
    "{\n"
    "  typeswitch(head($arg))\n"
    "  case empty-sequence() return $result\n"
    "  case $head as xs:yearMonthDuration return yearMonthDuration-max(tail($arg), if($head gt $result) then $head else $result)\n"
    "  default return error(xs:QName(\"err:FORG0006\"), \"Uncomparable items in argument to fn:max() function\")\n"
    "}\n"
  },
  {
    "dayTimeDuration-max", 2, true, 602, 1,
    "declare private function dayTimeDuration-max($arg as xs:anyAtomicType*, $result as xs:dayTimeDuration) as xs:dayTimeDuration\n"
    "{\n"
    "  typeswitch(head($arg))\n"
    "  case empty-sequence() return $result\n"
    "  case $head as xs:dayTimeDuration return dayTimeDuration-max(tail($arg), if($head gt $result) then $head else $result)\n"
    "  default return error(xs:QName(\"err:FORG0006\"), \"Uncomparable items in argument to fn:max() function\")\n"
    "}\n"
  },
  {
    "min", 1, false, 610, 1,
    "declare function min($arg as xs:anyAtomicType*) as xs:anyAtomicType?\n"
    "{\n"
    "  min($arg, default-collation())\n"
    "}\n"
  },
  {
    "min", 2, false, 615, 1,
    "declare function min($arg as xs:anyAtomicType*, $collation as xs:string) as xs:anyAtomicType?\n"
    "{\n"
    "  typeswitch(head($arg))\n"
    "  case empty-sequence() return ()\n"
    "  case $head as xs:untypedAtomic | xs:double return double-min(tail($arg), xs:double($head))\n"
    "  case $head as xs:float return float-min(tail($arg), $head)\n"
    "  case $head as xs:decimal return decimal-min(tail($arg), $head)\n"
    "  case $head as xs:anyURI | xs:string return string-min(tail($arg), xs:string($head), $collation)\n"
    "  case $head as xs:boolean return boolean-min(tail($arg), $head)\n"
    "  case $head as xs:date return date-min(tail($arg), $head)\n"
    "  case $head as xs:time return time-min(tail($arg), $head)\n"
    "  case $head as xs:dateTime return dateTime-min(tail($arg), $head)\n"
    "  case $head as xs:yearMonthDuration return yearMonthDuration-min(tail($arg), $head)\n"
    "  case $head as xs:dayTimeDuration return dayTimeDuration-min(tail($arg), $head)\n"
    "  default return error(xs:QName(\"err:FORG0006\"), \"Uncomparable items in argument to fn:min() function\")\n"
    "}\n"
  },
  {
    "double-min", 2, true, 632, 1,
    "declare private function double-min($arg as xs:anyAtomicType*, $result as xs:double) as xs:double\n"
    "{\n"
    "  typeswitch(head($arg))\n"
    "  case empty-sequence() return $result\n"
    "  case $head as xs:untypedAtomic | xs:double | xs:float | xs:decimal return\n"
    "    let $head := xs:double($head) return\n"
    "      double-min(tail($arg), if($head lt $result or $head ne $head) then $head else $result)\n"
    "  default return error(xs:QName(\"err:FORG0006\"), \"Uncomparable items in argument to fn:min() function\")\n"
    "}\n"
  },
  {
    "float-min", 2, true, 642, 1,
    "declare private function float-min($arg as xs:anyAtomicType*, $result as xs:float) as xs:anyAtomicType\n"
    "{\n"
    "  typeswitch(head($arg))\n"
    "  case empty-sequence() return $result\n"
    "  case $head as xs:untypedAtomic | xs:double return double-min($arg, xs:double($result))\n"
    "  case $head as xs:float | xs:decimal return\n"
    "    let $head := xs:float($head) return\n"
    "      float-min(tail($arg), if($head lt $result or $head ne $head) then $head else $result)\n"
    "  default return error(xs:QName(\"err:FORG0006\"), \"Uncomparable items in argument to fn:min() function\")\n"
    "}\n"
  },
  {
    "decimal-min", 2, true, 653, 1,
    "declare private function decimal-min($arg as xs:anyAtomicType*, $result as xs:decimal) as xs:anyAtomicType\n"
    "{\n"
    "  typeswitch(head($arg))\n"
    "  case empty-sequence() return $result\n"
    "  case $head as xs:untypedAtomic | xs:double return double-min($arg, xs:double($result))\n"
    "  case $head as xs:float return float-min($arg, xs:float($result))\n"
    "  case $head as xs:decimal return decimal-min(tail($arg), if($head lt $result) then $head else $result)\n"
    "  default return error(xs:QName(\"err:FORG0006\"), \"Uncomparable items in argument to fn:min() function\")\n"
    "}\n"
  },
  {
    "string-min", 3, true, 663, 1,
    "declare private function string-min($arg as xs:anyAtomicType*, $result as xs:string, $collation as xs:string) as xs:string\n"
    "{\n"
    "  typeswitch(head($arg))\n"
    "  case empty-sequence() return $result\n"
    "  case $head as xs:string | xs:anyURI return\n"
    "    string-min(tail($arg), if(compare($head, $result, $collation) lt 0) then xs:string($head) else $result, $collation)\n"
    "  default return error(xs:QName(\"err:FORG0006\"), \"Uncomparable items in argument to fn:min() function\")\n"
    "}\n"
  },
  {
    "boolean-min", 2, true, 672, 1,
    "declare private function boolean-min($arg as xs:anyAtomicType*, $result as xs:boolean) as xs:boolean\n"
    "{\n"
    "  typeswitch(head($arg))\n"
    "  case empty-sequence() return $result\n"
    "  case $head as xs:boolean return boolean-min(tail($arg), if($head lt $result) then $head else $result)\n"
    "  default return error(xs:QName(\"err:FORG0006\"), \"Uncomparable items in argument to fn:min() function\")\n"
    "}\n"
  },
  {
    "date-min", 2, true, 680, 1,
    "declare private function date-min($arg as xs:anyAtomicType*, $result as xs:date) as xs:date\n"
    "{\n"
    "  typeswitch(head($arg))\n"
    "  case empty-sequence() return $result\n"
    "  case $head as xs:date return date-min(tail($arg), if($head lt $result) then $head else $result)\n"
    "  default return error(xs:QName(\"err:FORG0006\"), \"Uncomparable items in argument to fn:min() function\")\n"
    "}\n"
  },
  {
    "time-min", 2, true, 688, 1,
    "declare private function time-min($arg as xs:anyAtomicType*, $result as xs:time) as xs:time\n"
    "{\n"
    "  typeswitch(head($arg))\n"
    "  case empty-sequence() return $result\n"
    "  case $head as xs:time return time-min(tail($arg), if($head lt $result) then $head else $result)\n"
    "  default return error(xs:QName(\"err:FORG0006\"), \"Uncomparable items in argument to fn:min() function\")\n"
    "}\n"
  },
  {
    "dateTime-min", 2, true, 696, 1,
    "declare private function dateTime-min($arg as xs:anyAtomicType*, $result as xs:dateTime) as xs:dateTime\n"
    "{\n"
    "  typeswitch(head($arg))\n"
    "  case empty-sequence() return $result\n"
    "  case $head as xs:dateTime return dateTime-min(tail($arg), if($head lt $result) then $head else $result)\n"
    "  default return error(xs:QName(\"err:FORG0006\"), \"Uncomparable items in argument to fn:min() function\")\n"
    "}\n"
  },
  {
    "yearMonthDuration-min", 2, true, 704, 1,
    "declare private function yearMonthDuration-min($arg as xs:anyAtomicType*, $result as xs:yearMonthDuration) as xs:yearMonthDuration\n"
    "{\n"
    "  typeswitch(head($arg))\n"
    "  case empty-sequence() return $result\n"
    "  case $head as xs:yearMonthDuration return yearMonthDuration-min(tail($arg), if($head lt $result) then $head else $result)\n"
    "  default return error(xs:QName(\"err:FORG0006\"), \"Uncomparable items in argument to fn:min() function\")\n"
    "}\n"
  },
  {
    "dayTimeDuration-min", 2, true, 712, 1,
    "declare private function dayTimeDuration-min($arg as xs:anyAtomicType*, $result as xs:dayTimeDuration) as xs:dayTimeDuration\n"
    "{\n"
    "  typeswitch(head($arg))\n"
    "  case empty-sequence() return $result\n"
    "  case $head as xs:dayTimeDuration return dayTimeDuration-min(tail($arg), if($head lt $result) then $head else $result)\n"
    "  default return error(xs:QName(\"err:FORG0006\"), \"Uncomparable items in argument to fn:min() function\")\n"
    "}\n"
  },
  {
    "map", 2, false, 725, 1,
    "declare function map($f as function(item()) as item()*, $seq as item()*) as item()*\n"
    "{\n"
    "  if(empty($seq)) then ()\n"
    "  else ($f(head($seq)), map($f, tail($seq)))\n"
    "}\n"
  },
  {
    "filter", 2, false, 731, 1,
    "declare function filter($f as function(item()) as xs:boolean, $seq as item()*) as item()*\n"
    "{\n"
    "  if(empty($seq)) then ()\n"
    "  else (\n"
    "    if($f(head($seq))) then head($seq) else (),\n"
    "    filter($f, tail($seq))\n"
    "  )\n"
    "}\n"
  },
  {
    "fold-left", 3, false, 740, 1,
    "declare function fold-left($f as function(item()*, item()) as item()*, $zero as item()*,\n"
    "  $seq as item()*) as item()*\n"
    "{\n"
    "  if(empty($seq)) then $zero\n"
    "  else fold-left($f, $f($zero, head($seq)), tail($seq))\n"
    "}\n"
  },
  {
    "fold-right", 3, false, 747, 1,
    "declare function fold-right($f as function(item(), item()*) as item()*, $zero as item()*,\n"
    "  $seq as item()*) as item()*\n"
    "{\n"
    "  if(empty($seq)) then $zero\n"
    "  else $f(head($seq), fold-right($f, $zero, tail($seq)))\n"
    "}\n"
  },
  {
    "map-pairs", 3, false, 754, 1,
    "declare function map-pairs($f as function(item(), item()) as item()*, $seq1 as item()*,\n"
    "  $seq2 as item()*) as item()*\n"
    "{\n"
    "   if(empty($seq1) or empty($seq2)) then ()\n"
    "   else (\n"
    "     $f(head($seq1), head($seq2)),\n"
    "     map-pairs($f, tail($seq1), tail($seq2))\n"
    "   )\n"
    "}\n"
  },
  { 0, 0, 0, 0, 0 }
};

static const DelayedModule fn_module = { fn_file, fn_prefix, fn_uri, fn_functions };
