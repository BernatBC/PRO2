 /* Pre: el parametre implicit no es buit */
 /* Post: el resultat es la suma del cami de suma maxima del parametre implicit */
 T max_suma_cami() const {
   return max_suma(primer_node);
 }

 T max_suma(node_arbreGen* n) const {
   if (n == NULL) return 0;
   T max = 0;
   for (int i = 0; i < n->seg.size(); ++i) {
     T par = max_suma(n->seg[i]);
     if (par > max) max = par;
   }
   return max + n->info;
 }
