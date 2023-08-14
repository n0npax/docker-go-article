FROM golang:latest as builder
ENV CGO_ENABLED=0
WORKDIR /workspace
RUN go env -w GOCACHE=/go-cache
RUN go env -w GOMODCACHE=/gomod-cache
COPY ./src/go.* ./
RUN --mount=type=cache,target=/gomod-cache \
  go mod download
COPY ./src ./
RUN --mount=type=cache,target=/gomod-cache --mount=type=cache,target=/go-cache \
  go build -o app ./...

FROM scratch AS final
COPY --from=builder /usr/share/zoneinfo /usr/share/zoneinfo
ENV TZ Australia/Sydney

COPY --from=builder /etc/ssl/certs/ca-certificates.crt /etc/ssl/certs/
COPY --from=builder /workspace/app /bin/app

USER 65333
ENTRYPOINT ["/bin/app"]