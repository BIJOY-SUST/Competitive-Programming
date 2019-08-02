for k from 1 to |V|
      for i from 1 to |V|
         for j from 1 to |V|
            if matrix[i][k] + matrix[k][j] < matrix[i][j] then
               matrix[i][j] ← matrix[i][k] + matrix[k][j]
               next[i][j] ← next[i][k]


findPath(i, j)
   path = [i]
   while i ≠ j
       i ← next[i][j]
       path.append(i)
   return path
