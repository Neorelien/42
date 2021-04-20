FROM alpine:latest

#tools
RUN apk update
RUN apk add openrc openssl openssh nginx

#config files
#RUN rm -rf /etc/nginx/nginx.conf /etc/ssh/sshd_config
#ADD /srcs/nginx.conf /etc/nginx/
#ADD /srcs/sshd_config /etc/ssh/

#index
RUN mkdir /www
ADD /srcs/index.html /www/

# port listening
EXPOSE 443 22 80

#scripts
RUN mkdir /script 
ADD ./srcs/init.sh /script/init.sh
VOLUME ["/sys/fs/cgroup"]

# SSL configuration
RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 -subj '/C=FR/ST=75/L=Paris/CN=awer' -keyout /etc/ssl/certs/localhost.key -out /etc/ssl/certs/localhost.crt

CMD /script/init.sh && /bin/sh
