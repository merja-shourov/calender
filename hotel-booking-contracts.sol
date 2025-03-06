// SPDX-License-Identifier: MIT
pragma solidity ^0.8.13;

contract HotelBook {
    // Owner of this hotel
    address payable owner;

    // Hotel vacent or occupy
    enum Status {
        vacent,
        occupied
    }

    Status public currentStatus;

    constructor() {
        owner = payable(msg.sender);
        currentStatus = Status.vacent;
    }
    modifier onlyWhileVacent() {
        // check room status
        require(currentStatus == Status.vacent, "Hotel room are not empty");
        _;
    }

    modifier costs(uint _amount) {
        // check amount
        require(msg.value >= _amount, "Invalid Ether");
        _;
    }

    function bookHotel() public payable onlyWhileVacent() costs(2 ether){
        owner.transfer(msg.value);
        currentStatus = Status.occupied;
    }
}
