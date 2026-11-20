# Universal payment gateway

## Design overview
PaymentGateway defines the common abstract interface. CreditCardGateway and CryptoGateway provide their own validation and capture behaviour. The driver uses a PaymentGateway pointer to demonstrate late binding.

## Structured pseudo-code
```text
ABSTRACT CLASS PaymentGateway
    VIRTUAL DESTRUCTOR()
    ABSTRACT METHOD Authorize(amount : REAL) RETURNS BOOLEAN
    ABSTRACT METHOD Capture() RETURNS BOOLEAN
ENDCLASS
CLASS CreditCardGateway EXTENDS PaymentGateway
    cardNumber : STRING; cvv : STRING
    OVERRIDE METHOD Authorize(amount)
        RETURN LENGTH(cardNumber)=16 AND LENGTH(cvv)=3 AND amount>0
    END
    OVERRIDE METHOD Capture() DISPLAY "Card capture"; RETURN TRUE END
ENDCLASS
CLASS CryptoGateway EXTENDS PaymentGateway
    walletHash : STRING; gasAvailable : REAL
    OVERRIDE METHOD Authorize(amount)
        RETURN STARTS_WITH(walletHash,"0x") AND gasAvailable>=0.01 AND amount>0
    END
    OVERRIDE METHOD Capture() DISPLAY "Crypto capture"; RETURN TRUE END
ENDCLASS
BEGIN
    gatewayPtr <- NEW CryptoGateway("0xABCDEF",0.02)
    IF gatewayPtr->Authorize(1500.00) THEN
        DISPLAY "Authorization approved"
        gatewayPtr->Capture()
    ELSE DISPLAY "Authorization rejected"
    ENDIF
    DELETE gatewayPtr
END
```

## Dispatch trace
| Step | Operation | Result |
|---|---|---|
| 1 | Base pointer assigned CryptoGateway object | Runtime type = CryptoGateway |
| 2 | `Authorize(1500.00)` | Crypto validation runs; valid prefix and gas |
| 3 | `Capture()` | Crypto capture implementation runs |
| 4 | Delete through base pointer | Virtual destructor chain is used |
