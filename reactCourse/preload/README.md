# Preload the npm cache

This project preloads the npm cache to make the course more nearly independent of the network.

## Start

From this folder do:

```
npm run installAll
```

This will do an ```npm install``` on the parent folder as well as any subfolders.

This has the effect of loading the npm cache with all the modules used in this class.

## Other commands

```
npm run clean
```
This will remove all the ```node_modules``` folder in this folder as well as any subfolders.

