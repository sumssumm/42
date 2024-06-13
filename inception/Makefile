# Makefile

# 변수 정의
DOCKER_COMPOSE = docker compose -f srcs/docker-compose.yml
DOCKER_EXEC = docker exec -it

# 기본 대상
.PHONY: all up down clean fclean re

all: up

# 컨테이너 실행 대상
up:
	# mkdir -p /home/${USER}/data/mariadb
	# mkdir -p /home/${USER}/data/wordpress
	$(DOCKER_COMPOSE) up --build

# 컨테이너 종료 대상
down:
	$(DOCKER_COMPOSE) down

wordpress:
	$(DOCKER_EXEC) wordpress /bin/sh

nginx:
	$(DOCKER_EXEC) nginx /bin/sh

mariadb:
	$(DOCKER_EXEC) mariadb /bin/sh

# 도커 이미지 삭제 대상
clean:
	$(DOCKER_COMPOSE) down --rmi all

# 볼륨까지 삭제하는 전체 정리 대상
fclean: clean
	# rm -rf /home/${USER}/data/

# 재빌드 및 재실행 대상
re: fclean all