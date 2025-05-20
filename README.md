Proiect "Snake Game"
Proiectul meu este o încercare de a implementa un joc Snake utilizând limbajul C,
librării standard dar și o librărie pentru partea vizuală - RayLib.

Pentru a rula jocul sunt necesare:
    -Librăria RayLib, ce poate fi instalată aici: https://github.com/raysan5/raylib.git
    -Compilator GCC

Pentru a complia jocul tastăm comanda "make", iar pentru al rula comanda "./game"
(SS)

Sarpele se mișcă folosind WASD.

Partea de cod e structurată astfel:
(SS)
    -în "src" se află fișierele .c 
    -în "include" fișierele .h
    -în "graphics" sunt texturile folosite

Cum lucrează codul:
În primul rând am inițializat o fereastră cu comanda InitWindow ce ia ca parametrii lungimea si lățimea fereastrei.
Codul meu are 2 obiecte principale reprezentate prin structuri: Snake și Apple.
(SS)
Pentru șarpe a fost necesară implementarea unei cozi cu ieșire și intare dublă (deque), care păstrează coordonatele.
Mișcarea șarpelui se face cu ajutorul funcțiilor PopRear și PushFront, dând pop la coadă când e necesar și push la 
următoarea coordonată.
Funcții în deque: PopFront/Rear, PushFront/Rear, IsEmpty, MakeNode și MakeDeque.
(SS)
Șarpele are coordonate și lungime inițială, valori la care se întoarce la fiecare început de joc.
Mișcarea se face în funcția UpdatePosition care verifică dacă șarpele a mâncat, dacă da, push-ăm un nou cap,
dacă nu, dăm și pop la coadă. Mișcarea se face în direcția determinată de utilizator prin comanda IsKeyPressed
(SS)
Deoarece inițial jocul merge pe 60 fps, a fost necesar și implementarea funcției EventTrigger ce lucrează ca un clock divider
Șarpele are coliziuni:
    -cu mărul, schimbând variabila "ate" și determinând modul următor de mișcare
    -cu marginile și cu el insuși ce determină terminarea jocului
Mărul apare random pe teren, excluzând coordonatele ocupate de șarpe.
Scorul este numărul de mere mâncate înmulțit cu 100.
Când se ajunge la funcția GameOver, jocul e resetat, pus pe pauză și așteaptă imputul utilizatorului.

Adiții:
    -Meniuri de start, joc, pauză, endgame implementate cu ajutorul unui enum de meniuri, schimbând între elementele lui.
    -Highscore care să-l țină într-un fișier penru al păstra chiar și dacă jocul e închis.
    -Textură pentru șarpe.

Probleme:
    -Când o rundă se termină, programul ține minte ultimul input și nu permite opposite movement deși e un joc nou.
    -Maximize Window arată rău.
    -Funcții care arată rău, prea mulți parametri.
