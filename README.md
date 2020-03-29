# Sinc

_*S*inc *I*s *N*ot *C*onvoluted_

Sinc is intended as a way to synchronize, peer-to-peer, all data between
devices. Spiritually, it is inspired by [Syncthing](https://syncthing.net/).

However, unlike _syncthing_, it exposes ways to transfer data, with plugins
handling specific data. Furthermore, it uses a multitude of discovery methods
to find other peers.

## Table of Contents
- [Requirements](#requirements)
- [Installation](#installation)
- [Contributing](#contributing)
- [Support](#support)
- [License](#license)
- [Thank You](#thank-you)

## Requirements

_Sinc_ is mostly written in `C++`.

The requirements can be fetched by running:
```bash
sudo pacman -S fmt spdlog libconfig cmake catch2
```

### Compilation

Compilation should be as simple as:
```bash
cmake . && make
```

### Running

You should be able to run the software with:
```bash
./sinc
```

## Contributing

Please do submit a pull request to resolve an issue.

## Support

You can reach out to me here:
- [Website](https://markovejnovic.com/)
- [Instagram](marko.vejnovic.42)
- [LinkedIn](https://www.linkedin.com/in/markovejnovic/)

## License
This software is licensed under the GPLv3 license.

## Thank you
- Thank you [fvcproductions](https://github.com/fvcproductions/) for your
  [README.md](https://gist.github.com/fvcproductions/1bfc2d4aecb01a834b46)
  guide.

