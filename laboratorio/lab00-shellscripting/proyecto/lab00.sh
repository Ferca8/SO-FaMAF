# Ejercicio 1
# Averiguar el modelo de procesador de mi equipo.
cat /proc/cpuinfo | grep "model name"

# Ejercicio 2
# Determinar cuántas unidades de ejecución tiene el procesador.
cat /proc/cpuinfo | grep "model name" | wc -l

# Ejercicio 3
# Convertir el nombre real de cada superhéroe (heroes.csv) a un usuario con todos sus caracteres en minúsculas y sin espacios.
wget https://raw.githubusercontent.com/dariomalchiodi/superhero-datascience/master/content/data/heroes.csv | awk -F ";" '{print $2}' heroes.csv | tr 'A-Z' 'a-z' | tr -d ' ' | grep -v "^$"

# Ejercicio 4
# Calcular el día de máxima temperatura (máximo de máximas) y el día de mínima temperatura (mínimo de mínimas) de la ciudad de Córdoba (weather_cordoba.in).
sort -n -k6 weather_cordoba.in | awk 'NR==1 {print $1,$2,$3}' # Día con la menor temperatura histórica
sort -nr -k5 weather_cordoba.in | awk 'NR==1 {print $1,$2,$3}' # Día con la mayor temperatura histórica

# Ejercicio 5
# Ordenar el listado de jugadores (atpplayers.in) según la posición en el ranking.
sort -n -k3 atpplayers.in

# Ejercicio 6
# Ordenar la tabla del campeonato de la Superliga (superliga.in) según la cantidad de puntos, y desempatar por diferencia de goles.
awk '{print $0,$7-$8}' superliga.in | sort -nr -k2 -k9

# Ejercicio 7
# Construir una secuencia de comandos de shell para imprimir por consola la MAC address de su interfaz ethernet.
ip link show | grep ether | awk '{print $2}'

# Ejercicio 8
# a) Crear una carpeta con el nombre de la serie y dentro de ella crear 10 archivos con un nombre como fma_S01EXX_es.srt, donde XX es el número de capítulo, desde 1 hasta 10.
mkdir Game-of-Thrones && cd Game-of-Thrones && for i in {01..10}; do touch "GOT_S01E${i}_es.srt"; done

# b) Con un segundo comando (el que usarían realmente), cambiar el nombre de cada archivo sacando el sufijo _es.
for i in {01..10}; do mv GOT_S01E${i}_es.srt GOT_S01E${i}.srt; done