find . -name "*.sh" -type f -exec basename {} \; | sed -e 's/\.sh$//'
