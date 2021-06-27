find . \( -type f -o -type d \) | wc -l | sed 's/^ *//' | sed 's: ::g'
