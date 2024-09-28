
PROGRAM="./philo 5 800 200 200 " 


while true
do
    echo "Lancement du programme..."
    

    $PROGRAM &


    PID=$!


    sleep 10


    echo "Arrêt du programme..."
    kill $PID

   
    sleep 1

done
