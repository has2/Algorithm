{\rtf1\ansi\deff0\nouicompat{\fonttbl{\f0\fnil DotumChe;}{\f1\fnil\fcharset129 \'b8\'bc\'c0\'ba \'b0\'ed\'b5\'f1;}}
{\colortbl ;\red128\green128\blue128;\red0\green0\blue0;\red163\green21\blue21;\red0\green0\blue255;\red43\green145\blue175;\red0\green128\blue128;}
{\*\generator Riched20 10.0.14393}\viewkind4\uc1 
\pard\sa200\sl276\slmult1\cf1\f0\fs19\lang18 #include\cf2  \cf3 <cstdio>\cf2\par
\cf1 #include\cf2  \cf3 <tuple>\cf2\par
\cf1 #include\cf2  \cf3 <utility>\cf2\par
\cf1 #include\cf2  \cf3 <algorithm>\cf2\par
\cf1 #include\cf2  \cf3 <vector>\cf2\par
\cf1 #include\cf2  \cf3 <set>\cf2\par
\cf4 using\cf2  \cf4 namespace\cf2  std;\par
\cf4 int\cf2  N, start, endp;\par
\cf4 int\cf2  min_result = 999999999;\par
\cf5 vector\cf2  < \cf5 pair\cf2 <\cf4 int\cf2 , \cf4 int\cf2 >> result;\par
\par
\cf4 void\cf2  solve(\cf5 vector\cf2 <\cf5 tuple\cf2 <\cf4 int\cf2 , \cf4 int\cf2 , \cf4 int\cf2 >> \cf1 obs\cf2 ,\cf4 int\cf2  \cf1 cur\cf2 ,\cf4 int\cf2  \cf1 cur_x\cf2 ,\cf4 int\cf2  \cf1 cur_y\cf2 ,\cf4 int\cf2  \cf1 cur_cost\cf2 )\{\par
\par
\tab\cf4 if\cf2  (\cf1 cur_cost\cf2  > min_result) \{\par
\tab\tab\cf4 return\cf2 ; \par
\tab\}\par
\par
\tab\cf4 int\cf2  result_cost;\par
\par
\tab\cf4 if\cf2  (\cf1 cur\cf2  == N - 1) \{\par
\tab\tab result_cost = \cf1 cur_cost\cf2  + endp - \cf1 cur_x\cf2 ;\par
\tab\tab\cf4 if\cf2  (result_cost <= min_result) \{\par
\tab\tab\tab min_result = result_cost;\par
\tab\tab\tab result.push_back(make_pair(result_cost, \cf1 cur_y\cf2 ));\par
\tab\tab\}\par
\tab\tab\cf4 return\cf2 ;\par
\tab\}\par
\par
\tab\cf4 int\cf2  nextidx, diff_up, diff_down;\par
\par
\tab\cf4 for\cf2  (\cf4 int\cf2  i = \cf1 cur\cf2  + 1; i < N; i++) \{\par
\tab\tab\cf4 if\cf2  (get<1>(\cf1 obs\cf6 [\cf2 i\cf6 ]\cf2 ) < \cf1 cur_y\cf2  && \cf1 cur_y\cf2  < get<2>(\cf1 obs\cf6 [\cf2 i\cf6 ]\cf2 )) \{\par
\tab\tab\tab diff_up = get<2>(\cf1 obs\cf6 [\cf2 i\cf6 ]\cf2 ) - \cf1 cur_y\cf2 ; diff_down = \cf1 cur_y\cf2  - get<1>(\cf1 obs\cf6 [\cf2 i\cf6 ]\cf2 );\par
\tab\tab\tab nextidx = i;\par
\tab\tab\tab\cf4 break\cf2 ;\par
\tab\tab\}\par
\par
\tab\tab\cf4 if\cf2  (i == N - 1) \{\par
\tab\tab\tab result_cost =\cf1 cur_cost\cf2  + endp - \cf1 cur_x\cf2 ;\par
\tab\tab\tab\cf4 if\cf2  (result_cost <= min_result) \{\par
\tab\tab\tab\tab min_result = result_cost;\par
\tab\tab\tab\tab result.push_back(make_pair(result_cost, \cf1 cur_y\cf2 ));\par
\tab\tab\tab\}\par
\tab\tab\tab\cf4 return\cf2 ;\par
\tab\tab\}\par
\tab\}\par
\par
\tab\cf1 cur_cost\cf2  = \cf1 cur_cost\cf2  + (get<0>(\cf1 obs\cf6 [\cf2 nextidx\cf6 ]\cf2 )-\cf1 cur_x\cf2 );\par
\tab\cf1 cur_x\cf2  = get<0>(\cf1 obs\cf6 [\cf2 nextidx\cf6 ]\cf2 );\par
\tab  \par
\tab solve(\cf1 obs\cf2 , nextidx, \cf1 cur_x\cf2 , \cf1 cur_y\cf2  + diff_up, \cf1 cur_cost\cf2  + diff_up);\par
\tab solve(\cf1 obs\cf2 , nextidx, \cf1 cur_x\cf2 , \cf1 cur_y\cf2  - diff_down, \cf1 cur_cost\cf2  + diff_down);\par
\}\par
\par
\cf4 int\cf2  main(\cf4 void\cf2 )\par
\{\par
\par
\tab\cf5 vector\cf2 <\cf5 tuple\cf2 <\cf4 int\cf2 , \cf4 int\cf2 , \cf4 int\cf2 >> obstacle;\par
\tab\cf5 vector\cf2 <\cf4 int\cf2 > result_y;\par
\tab\cf4 int\cf2  nextidx;\par
\tab scanf(\cf3 "%d%d%d"\cf2 , &N, &start,&endp);\par
\tab\cf4 for\cf2  (\cf4 int\cf2  i = 0; i < N; i++) \{\par
\tab\tab\cf4 int\cf2  a, b, c;\par
\tab\tab scanf(\cf3 "%d%d%d"\cf2 , &a, &b, &c);\par
\tab\tab obstacle.push_back(make_tuple(a, b, c));\par
\tab\}\par
\tab\par
\tab sort(obstacle.begin(), obstacle.end());\par
\par
\tab solve(obstacle, -1, 0, start, 0);\par
\par
\tab sort(result.begin(), result.end());\par
\par
\tab\cf5 set\cf2 <\cf4 int\cf2 > s;\par
\tab\cf4 int\cf2  min = result\cf6 [\cf2 0\cf6 ]\cf2 .first;\par
\tab\cf4 int\cf2  cnt = 0;\par
\tab\cf5 vector\cf2 <\cf5 pair\cf2 <\cf4 int\cf2 ,\cf4 int\cf2 >>::\cf5 iterator\cf2  iter = result.begin();\par
\tab\cf4 for\cf2  (iter \cf6 =\cf2  result.begin(); iter \cf6 !=\cf2  result.end(); \cf6 ++\cf2 iter) \{\par
\tab\tab\cf4 if\cf2  (min == iter\cf6 ->\cf2 first) \{\par
\tab\tab\tab s.insert(iter\cf6 ->\cf2 second);\par
\tab\tab\tab cnt++;\par
\tab\tab\}\par
\tab\tab\cf4 else\cf2  \{\par
\tab\tab\tab\cf4 break\cf2 ;\par
\tab\tab\}\par
\tab\}\par
\par
\tab cnt = s.size();\par
\tab\cf5 set\cf2 <\cf4 int\cf2 >::\cf5 const_iterator\cf2  pos;\par
\tab\cf4 for\cf2  (pos \cf6 =\cf2  s.begin(); pos \cf6 !=\cf2  s.end(); \cf6 ++\cf2 pos)\par
\tab\tab result_y.push_back(\cf6 *\cf2 pos);\par
\tab\par
\tab sort(result_y.begin(), result_y.end());\par
\par
\tab printf(\cf3 "%d\\n%d "\cf2 , min,cnt);\par
\tab\cf4 for\cf2  (\cf4 int\cf2  i = 0; i < cnt; i++)\par
\tab\tab printf(\cf3 "%d "\cf2 , result_y\cf6 [\cf2 i\cf6 ]\cf2 );\par
\}\par
\cf0\f1\fs20\par
}
 