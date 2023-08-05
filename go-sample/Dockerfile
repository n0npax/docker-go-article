FROM golang:latest as builder
ENV CGO_ENABLED 1
WORKDIR /workspace
RUN go env -w GOCACHE=/go-cache
COPY ./src ./
RUN --mount=type=cache,target=/go-cache go build -o app ./...
FROM scratch
COPY --from=builder /workspace/app /bin/app
USER 65333
ENTRYPOINT ["/bin/app"]