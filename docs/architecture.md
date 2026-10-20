# Architecture

- `ui/`: QML presentation and page navigation.
- `BankingController`: C++ state, demo login, and validated balance operations.
- `tests/`: Qt Test checks for authentication and deposit/withdrawal rules.

The controller is the single source of truth for the demo balance. In a real banking product, balances and transaction authorization must be enforced by a secure backend, not by a desktop client.
