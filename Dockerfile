FROM scratch
ADD tailor /tailor
ADD alg.ter /tailor
CMD ["/tailor"]